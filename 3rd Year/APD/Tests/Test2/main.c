#include<mpi.h>
#include<stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define CONVERGENCE_COEF 100

/**
 * Run: mpirun -np 12 ./a.out
 */

static int num_neigh;
static int *neigh;

void read_neighbours(int rank) {
    FILE *fp;
    char file_name[15];
    sprintf(file_name, "./files/%d.in", rank);

    fp = fopen(file_name, "r");
	fscanf(fp, "%d", &num_neigh);

	neigh = malloc(sizeof(int) * num_neigh);

	for (size_t i = 0; i < num_neigh; i++)
		fscanf(fp, "%d", &neigh[i]);
}

void compute_topology(int rank, int nProcesses) {
	int **A = (int **) calloc(nProcesses, sizeof(int*));
	for (int i = 0; i < nProcesses; i++) {
		A[i] = (int *) calloc(nProcesses, sizeof(int));
	}
	
	for (int i = 0; i < num_neigh; i++) {
		A[neigh[i]][rank] = 1;
		A[rank][neigh[i]] = 1;
	}
	int **vA = (int **) calloc(nProcesses, sizeof(int*));
	for (int i = 0; i < nProcesses; i++) {
		vA[i] = (int *) calloc(nProcesses, sizeof(int));
	}
	
	for (int k = 0; k < CONVERGENCE_COEF; k++) {
		for (int i = 0; i < num_neigh; i++) {
			for (int j = 0; j < nProcesses; j++) {
				MPI_Send(A[j], nProcesses, MPI_INT, neigh[i], j, MPI_COMM_WORLD);
			}
		}
		for (int i = 0; i < num_neigh; i++) {
			for (int j = 0; j < nProcesses; j++) {
				MPI_Recv(vA[j], nProcesses, MPI_INT, MPI_ANY_SOURCE, j, MPI_COMM_WORLD, NULL);
			}
			for (int p = 0; p < nProcesses; p++) {
				for (int q = 0; q < nProcesses; q++) {
					if (vA[p][q] == 1 && A[p][q] != 1) {
						A[p][q] = vA[p][q];
						A[q][p] = vA[q][p];
					}
				}
			}
		}

	}

	MPI_Barrier(MPI_COMM_WORLD);
	if (rank == 0) {
		printf("A[][] =  \n");
		for (int i = 0; i < nProcesses; i++) {
			for (int j = 0; j < nProcesses; j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	}

}


int main(int argc, char * argv[]) {
	int rank, nProcesses, num_procs, leader;
	int *parents, **topology;

	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Request request;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nProcesses);

	if (nProcesses != 12) {
		printf("please run with: mpirun --oversubscribe -np 12 %s\n", argv[0]);
		MPI_Finalize();	
		exit(0);
	}
	 
	read_neighbours(rank);
	compute_topology(rank, nProcesses);
	
	
	
	MPI_Finalize();
	return 0;
}