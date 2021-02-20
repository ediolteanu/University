#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
int n;
int main (int argc, char *argv[])
{
    int numtasks, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int recv_num;

    // First process starts the circle.
    srand(42);
    n = rand();
    if (rank == 0) {
        // First process starts the circle.
        // Generate a random number.
        // Send the number to the next process.
        MPI_Status status;

        printf("Before send: process with rank %d has the number %d.\n", rank, n);
        MPI_Send(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&n, 1, MPI_INT, numtasks - 1, 0, MPI_COMM_WORLD, &status);
        printf("Process with rank %d, received %d with tag %d.\n",rank, n, status.MPI_TAG);

    } else if (rank == numtasks - 1) {
        // Last process close the circle.
        // Receives the number from the previous process.
        // Increments the number.
        // Sends the number to the first process.
		MPI_Status status;
        MPI_Recv(&n, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, &status);
        printf("Process with rank %d, received %d with tag %d.\n",
                rank, n, status.MPI_TAG);
        n = n + 2;
        MPI_Send(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

    } else {
        // Middle process.
        // Receives the number from the previous process.
        // Increments the number.
        // Sends the number to the next process.
    	MPI_Status status;

        MPI_Recv(&n, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, &status);
        printf("Process with rank %d, received %d with tag %d.\n",rank, n, status.MPI_TAG);
                
        n = n + 2;
        MPI_Send(&n, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
    }


    MPI_Finalize();

}

