
/* 
 * File:   count.cpp
 * Author: maxmya
 *
 * Created on 06 March 2016, 13:58
 */

#include <cstdlib>
#include <mpi.h>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

/*
 * 
 */



string NumberToString(int Number) {
    ostringstream ss;
    ss << Number;
    return ss.str();
}

int main(int argc, char** argv) {


    int rank, size;
    string outs = "";

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    

    int process = 50 / size;

    int start = rank*process +1   ;

    int end = (start+process+1);

    for (int i = start; i < end+1; i++) {

        outs += NumberToString(i);
    }

    printf ("Process %d display %s \n" , rank , outs.c_str());


    MPI_Finalize();



    return 0;
}



