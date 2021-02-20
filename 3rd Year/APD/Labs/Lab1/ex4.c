#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#define NUM_THREADS 4

void *f1(void *arg) {
  	long id = *(long*) arg;
  	for (int i = 0; i < 100; i++) {
  		printf("Hello World din thread-ul %ld, iteratia %d\n", id, i);
  	}
  	pthread_exit(NULL);
}

void *f2(void *arg) {
    long id = *(long*) arg;
  	for (int i = 0; i < 100; i++) {
  		printf("Salut din thread-ul %ld, iteratia %d\n", id, i);
  	}
  	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  long NUM_THREADS = sysconf(_SC_NPROCESSORS_CONF);
	pthread_t threads[NUM_THREADS];
  int r;
  int t;
  long id;
  void *status;
  long arguments[NUM_THREADS];
	
	printf("%ld\n", NUM_THREADS);
	
	arguments[0] = 0;
	arguments[1] = 1;
	
	r = pthread_create(&threads[0], NULL, f1, &arguments[0]);
	if (r) {
		printf("Eroare la crearea thread-ului %ld\n", id);
		exit(-1);
  }
	  
	t = pthread_create(&threads[1], NULL, f2, &arguments[1]);
	if (t) {
		printf("Eroare la crearea thread-ului %ld\n", id);
		exit(-1);
  }
  
  for (id = 0; id < 2; id++) {
	  r = pthread_join(threads[id], &status);

	  if (r) {
    		printf("Eroare la asteptarea thread-ului %ld\n", id);
    		exit(-1);
	  }
	}
	/*for (id = 0; id < NUM_THREADS; id++) {
		arguments[id] = id;
	  r = pthread_create(&threads[id], NULL, f, &arguments[id]);
    
	  if (r) {
  		printf("Eroare la crearea thread-ului %ld\n", id);
  		exit(-1);
	  }
	}

  for (id = 0; id < NUM_THREADS; id++) {
	  r = pthread_join(threads[id], &status);

	  if (r) {
    		printf("Eroare la asteptarea thread-ului %ld\n", id);
    		exit(-1);
	  }
	}*/

  	pthread_exit(NULL);
}
