/* 
 * File:   main.cpp
 * Author: maxmya
 *
 * Created on 06 March 2016, 13:33
 */

#include <cstdlib>
#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {


    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    if (rank % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }

    MPI_Finalize();
    return 0;




}

