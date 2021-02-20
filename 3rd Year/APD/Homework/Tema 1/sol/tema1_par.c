/*
 * APD - Tema 1
 * Octombrie 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

char *in_filename_julia;
char *in_filename_mandelbrot;
char *out_filename_julia;
char *out_filename_mandelbrot;
int P; // numarul de thread-uri
pthread_barrier_t barrier; //declararea barierei

//am declarat cate un set de variabilte globale pentru fiecare algoritm 
//pentru a fi mai usor de apelat functiile
int width1, height1, width2, height2;
int **result1, **result2;

// structura pentru un numar complex
typedef struct _complex {
	double a;
	double b;
} complex;

// structura pentru parametrii unei rulari
typedef struct _params {
	int is_julia, iterations;
	double x_min, x_max, y_min, y_max, resolution;
	complex c_julia;
} params;

params par1, par2;

int min(int a, int b) {
  if (a <= b) return a;
  return b;
}

// citeste argumentele programului
void get_args(int argc, char **argv)
{
	if (argc < 5) {
		printf("Numar insuficient de parametri:\n\t"
				"./tema1_par fisier_intrare_julia fisier_iesire_julia "
				"fisier_intrare_mandelbrot fisier_iesire_mandelbrot P\n");
		exit(1);
	}

	in_filename_julia = argv[1];
	out_filename_julia = argv[2];
	in_filename_mandelbrot = argv[3];
	out_filename_mandelbrot = argv[4];
	P = atoi(argv[5]);
}

// citeste fisierul de intrare
void read_input_file(char *in_filename, params* par)
{
	FILE *file = fopen(in_filename, "r");
	if (file == NULL) {
		printf("Eroare la deschiderea fisierului de intrare!\n");
		exit(1);
	}

	fscanf(file, "%d", &par->is_julia);
	fscanf(file, "%lf %lf %lf %lf",
			&par->x_min, &par->x_max, &par->y_min, &par->y_max);
	fscanf(file, "%lf", &par->resolution);
	fscanf(file, "%d", &par->iterations);

	if (par->is_julia) {
		fscanf(file, "%lf %lf", &par->c_julia.a, &par->c_julia.b);
	}

	fclose(file);
}

// scrie rezultatul in fisierul de iesire
void write_output_file(char *out_filename, int **result, int width, int height)
{
	int i, j;

	FILE *file = fopen(out_filename, "w");
	if (file == NULL) {
		printf("Eroare la deschiderea fisierului de iesire!\n");
		return;
	}

	fprintf(file, "P2\n%d %d\n255\n", width, height);
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			fprintf(file, "%d ", result[i][j]);
		}
		fprintf(file, "\n");
	}

	fclose(file);
}

// aloca memorie pentru rezultat
int **allocate_memory(int width, int height)
{
	int **result;
	int i;

	result = malloc(height * sizeof(int*));
	if (result == NULL) {
		printf("Eroare la malloc!\n");
		exit(1);
	}

	for (i = 0; i < height; i++) {
		result[i] = malloc(width * sizeof(int));
		if (result[i] == NULL) {
			printf("Eroare la malloc!\n");
			exit(1);
		}
	}

	return result;
}

// elibereaza memoria alocata
void free_memory(int **result, int height)
{
	int i;

	for (i = 0; i < height; i++) {
		free(result[i]);
	}
	free(result);
}

// ruleaza algoritmul Julia
void run_julia(params *par, int **result, int width, int height, int thread_id)
{
	int w, h, i;
	
	/* am paralelizat algoritmul pe linii. Astfel inaltimea este impartita in P 
	 sectiuni pe care lucreaza thread-urile */
  int start = thread_id * (double) height / P;
  int end = min(height, (thread_id + 1) * (double) height / P);
  
	for (w = 0; w < width; w++) {
		for (h = start; h < end; h++) {
			int step = 0;
			complex z = { .a = w * par->resolution + par->x_min,
							.b = h * par->resolution + par->y_min };

			while (sqrt(pow(z.a, 2.0) + pow(z.b, 2.0)) < 2.0 && step < par->iterations) {
				complex z_aux = { .a = z.a, .b = z.b };

				z.a = pow(z_aux.a, 2) - pow(z_aux.b, 2) + par->c_julia.a;
				z.b = 2 * z_aux.a * z_aux.b + par->c_julia.b;

				step++;
			}

			result[h][w] = step % 256;
		}
	}
  
  /* inainte de modificarea matricei rezultat trebuie sa ne asiguram ca
    algoritmul a ajuns la final */
  pthread_barrier_wait(&barrier);
  
	// transforma rezultatul din coordonate matematice in coordonate ecran
	/* deoarece facem interschimbari intre valorile din matrice este nevoie
	  sa impartim height / 2 in P sectiuni */
	start = thread_id * (double) height / (2 * P);
  end = min(height / 2 , (thread_id + 1) * (double) height / (2 * P));
	
  for (i = start; i < end; i++) {
	  int *aux = result[i];
	  result[i] = result[height - i - 1];
	  result[height - i - 1] = aux;
  }
	
}

// ruleaza algoritmul Mandelbrot
void run_mandelbrot(params *par, int **result, int width, int height, int thread_id)
{
	int w, h, i;
	
  /* am paralelizat algoritmul pe linii. Astfel inaltimea este impartita in P 
	  sectiuni pe care lucreaza thread-urile */
  int start = thread_id * (double) height / P;
  int end = min(height, (thread_id + 1) * (double) height / P);
  
	for (w = 0; w < width; w++) {
		for (h = start; h < end; h++) {
			complex c = { .a = w * par->resolution + par->x_min,
							.b = h * par->resolution + par->y_min };
			complex z = { .a = 0, .b = 0 };
			int step = 0;

			while (sqrt(pow(z.a, 2.0) + pow(z.b, 2.0)) < 2.0 && step < par->iterations) {
				complex z_aux = { .a = z.a, .b = z.b };

				z.a = pow(z_aux.a, 2.0) - pow(z_aux.b, 2.0) + c.a;
				z.b = 2.0 * z_aux.a * z_aux.b + c.b;

				step++;
			}

			result[h][w] = step % 256;
		}
	}

  /* inainte de modificarea matricei rezultat trebuie sa ne asiguram ca
    algoritmul a ajuns la final */
  pthread_barrier_wait(&barrier);
  
	// transforma rezultatul din coordonate matematice in coordonate ecran
	/* deoarece facem interschimbari intre valorile din matrice este nevoie
	  sa impartim height / 2 in P sectiuni */
	start = thread_id * (double) height / (2 * P);
  end = min(height / 2 , (thread_id + 1) * (double) height / (2 * P));
	
  for (i = start; i < end; i++) {
	  int *aux = result[i];
	  result[i] = result[height - i - 1];
	  result[height - i - 1] = aux;
  }
}

void *thread_function(void *arg) {
  int id = *(int *) arg;
	
	run_julia(&par1, result1, width1, height1, id);
	
	/* intre cei doi algoritmi nu este nevoie de o bariera deoarece am folosit
	  2 matrice result si exista bariera inaintea transformarii de coordonate
	  matematice in coordonate ecran din algoritmul julia, thread-urile pot
	  termina operatiile pe result1 si apoi sa treaca la algoritmul mandelbrot
	  care se foloseste de result2 fara sa existe conflict */
	
	run_mandelbrot(&par2, result2, width2, height2, id);
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	// se citesc argumentele programului
	get_args(argc, argv);
  
  // sunt initializate thread-urile si bariera
  int r;
  pthread_t threads[P];
  int thread_id[P];
  pthread_barrier_init(&barrier, NULL, P);
  
  // sunt facute toate citirile inainte de a incepe portiunea paralelizata
  read_input_file(in_filename_julia, &par1);
  width1 = (par1.x_max - par1.x_min) / par1.resolution;
	height1 = (par1.y_max - par1.y_min) / par1.resolution;
	result1 = allocate_memory(width1, height1);
	
  read_input_file(in_filename_mandelbrot, &par2);
  width2 = (par2.x_max - par2.x_min) / par2.resolution;
	height2 = (par2.y_max - par2.y_min) / par2.resolution;
	result2 = allocate_memory(width2, height2);
  
  // se creeaza threadurile
  for (int id = 0; id < P; id++) {
  		thread_id[id] = id;
		r = pthread_create(&threads[id], NULL, thread_function, &thread_id[id]);

		if (r) {
	  		printf("Eroare la crearea thread-ului %d\n", id);
	  		exit(-1);
		}
  }

  // dupa ce au terminat de lucru se da join la thread-uri
  for (int id = 0; id < P; id++) {
		r = pthread_join(threads[id], NULL);

		if (r) {
	  		printf("Eroare la asteptarea thread-ului %d\n", id);
	  		exit(-1);
		}
  }
  // este distrusa si bariera
  pthread_barrier_destroy(&barrier);
  
  // sunt apelate scrierile in fisiere si dezalocarea memoriei
  write_output_file(out_filename_julia, result1, width1, height1);
	free_memory(result1, height1);
	
  write_output_file(out_filename_mandelbrot, result2, width2, height2);
	free_memory(result2, height2); 
	
	return 0;
}
