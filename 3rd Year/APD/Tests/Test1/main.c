#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int N, P;
int *v;
pthread_barrier_t barrier;

struct argument {
  int id;
  int *sum;
};

int min(int a, int b) {
  if (a <= b) return a;
  return b;
}

void *f(void *arg) {
  struct argument aux = *(struct argument *) arg;
  int thread_id = aux.id;
  int start = thread_id * (double)N / P;
	int end = min((thread_id + 1) * (double)N / P, N);
	
	for (int i = start; i < end; i++) {
	  aux.sum[thread_id] += v[i];
	}
	//nu am reusit sa modific suma vectorului asta pe care l-am dat ca paramentru in arguments
	//astfel incat sa fie citit corect de catre thread-ul 0 si nu imi face suma bine.
  
  //cu un vector de sume global mergea problema corect.
	pthread_barrier_wait(&barrier);
	if (thread_id == 0) {
	  int suma = 0;
	  for (int i = 0; i < P; i++) {
	    suma += aux.sum[i];
	  }
	  printf("Suma vectorului este: %d\n", suma);
	}
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Numar insuficient de parametri: ./practic N P\n");
		exit(1);
  }
  
  int r;
  N = atoi(argv[1]);
  P = atoi(argv[2]);
  
  void *status;
  struct argument *arguments = (struct argument *) malloc(P * sizeof(struct argument));
  int *sum = (int *) calloc(P, sizeof(int));
  for (int i = 0; i < P; i++) {
    sum[i] = 0;
  }
  
  v = (int *) malloc(N * sizeof(int));
  pthread_t threads[P];
  pthread_barrier_init(&barrier, NULL, P);
  
  for (int i = 0; i < N; i++) {
    v[i] = i + 5;
  }
  
  for (int i = 0; i < P; i++) {
    arguments[i].id = i;
    arguments[i].sum = sum;
  }
  
  for (int id = 0; id < P; id++) {
		  r = pthread_create(&threads[id], NULL, f, &arguments[id]);
		if (r) {
	  		printf("Eroare la crearea thread-ului %d\n", id);
	  		exit(-1);
		}
  }

  for (int id = 0; id < P; id++) {
		r = pthread_join(threads[id], &status);

		if (r) {
	  		printf("Eroare la asteptarea thread-ului %d\n", id);
	  		exit(-1);
		}
  }
  pthread_barrier_destroy(&barrier);
  	
  return 0;
} 
