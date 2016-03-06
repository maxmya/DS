
/* 
 * File:   third.cpp
 * Author: maxmya
 *
 * Created on 06 March 2016, 14:49
 */

#include <cstdlib>
#include<iostream>
#include <mpi.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {



    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    int sum;

    int process = 1000 / size;


    int start = rank * process + 1;


    int end = (start + process);


    for (int i = start; i < end + 1; i++) {

        sum += i;

    }

    printf("Sum is %d on cpu %d \n", sum, rank);

    MPI_Finalize();


    return 0;
}

