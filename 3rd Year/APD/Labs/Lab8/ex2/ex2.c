#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#define ROOT 0

int main (int argc, char *argv[])
{
    int  numtasks, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    int rand_num;

    // Root process generates a random number.
    // Broadcasts to all processes.
    srand(42);
    rand_num = rand();
    if (rank == 0) {
    	
    	MPI_Bcast(&rand_num, 1, MPI_INT, 0, MPI_COMM_WORLD);
    } //else {
    // 	MPI_Status status;
    //     MPI_Recv(&rand_num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    //     printf("Process with rank %d, received %d with tag %d.\n",
    //             rank, rand_num, status.MPI_TAG);
    // }

    printf("Process [%d], after broadcast %d.\n", rank, rand_num);

    MPI_Finalize();

}

