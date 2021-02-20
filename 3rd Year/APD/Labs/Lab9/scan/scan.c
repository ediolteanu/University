#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#define MASTER 0

int main (int argc, char *argv[])
{
    int procs, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int value = 2 * rank + 1;
    int n;
    MPI_Status status;
    
    for (int i = 1; i < procs; i *= 2) {
        if (rank + i < procs) {
            MPI_Send(&value, 1, MPI_INT, rank + i, 0, MPI_COMM_WORLD);
        }
        if (rank - i >= 0) {
            MPI_Recv(&n, 1, MPI_INT, rank - i, 0, MPI_COMM_WORLD, &status);
            value += n;
        }
        
    }

    printf("Process [%d] has result = %d\n", rank, value);

    MPI_Finalize();

}

