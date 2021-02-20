#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
    schelet pentru exercitiul 5
*/

int* arr;
int array_size;
long cores;

int min(int a, int b) {
  if (a <= b) return a;
  return b;
}

void *f(void *arg) {
  long ID = *(long*) arg;
	int start = ID * (double)array_size / cores;
  int end = min((ID + 1) * (double)array_size / cores, array_size);
  for (int i = start; i < end; i++) {
      for (int j = 0; j < 1000000; j++) {
        arr[i] += 100;
      }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
      perror("Specificati dimensiunea array-ului\n");
      exit(-1);
  }

  array_size = atoi(argv[1]);

  arr = malloc(array_size * sizeof(int));
  for (int i = 0; i < array_size; i++) {
      arr[i] = i;
  }

  /*for (int i = 0; i < array_size; i++) {
      printf("%d", arr[i]);
      if (i != array_size - 1) {
          printf(" ");
      } else {
          printf("\n");
      }
  }*/

  cores = sysconf(_SC_NPROCESSORS_CONF); // 4
  //cores = 2;
  printf("nr threads: %ld", cores);
  pthread_t threads[cores];
  int r;
  long id;
  void *status;
  long arguments[cores];
  
	for (id = 0; id < cores; id++) {
		arguments[id] = id;
	  r = pthread_create(&threads[id], NULL, f, &arguments[id]);
    
	  if (r) {
  		printf("Eroare la crearea thread-ului %ld\n", id);
  		exit(-1);
	  }
	}

  for (id = 0; id < cores; id++) {
	  r = pthread_join(threads[id], &status);

	  if (r) {
    		printf("Eroare la asteptarea thread-ului %ld\n", id);
    		exit(-1);
	  }
	}

  /*for (int i = 0; i < array_size; i++) {
     printf("%d", arr[i]);
      if (i != array_size - 1) {
          printf(" ");
      } else {
          printf("\n");
      }
  }*/

	pthread_exit(NULL);
}
