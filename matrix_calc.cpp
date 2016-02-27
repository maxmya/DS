
/* 
 * File:   main.cpp
 * Author: maxmya
 *
 * Created on 27 February 2016, 14:32
 */

#include <cstdlib>
#include <iostream>
#include<stdlib.h>

using namespace std;

int main() {


    cout << "Hello , Welcome To Matrix Calculator" << endl;
    bool Bflag = true;
    while (Bflag) {


        cout << "Enter\n\t1 to multiply vector by matrix\n\t2 to multiply matrix by matrix\n\t3 to compute norm of a matrix\n\t4 to Exit" << endl;
        int userChoose;
        cin >> userChoose;
        switch (userChoose) {
            case 1:
            {
                int sizeX;
                cout << "Enter Size of Vector " << endl;
                cin >> sizeX;
                int vect [sizeX];
                int sizeY;
                cout << "Enter Size of Matrix " << sizeX << " by (enter Y) " << endl;
                cin >> sizeY;
                int matr [sizeX][sizeY];
                cout << "You have Vector 1 X " << sizeX << " and Matrix " << sizeX << " X " << sizeY << endl;
                int multblication [sizeY];
                for (int i = 0; i < sizeY; i++) {
                    multblication[i] = 0;
                }
                cout << "\t1 To fill them\n\t2 to randomly fill them" << endl;
                int choose;
                cin >> choose;
                switch (choose) {
                    case 1:
                    {
                        cout << "Fill the Vector first : " << endl;

                        for (int i = 0; i < sizeX; i++) {
                            cout << "Vector [" << i << "] = ";
                            cin >> vect[i];
                        }
                        cout << "\nFill the matrix row by row : " << endl;
                        for (int i = 0; i < sizeX; i++) {
                            for (int j = 0; j < sizeY; j++) {
                                cout << "Matrix [" << i << "][" << j << "] = ";
                                cin >> matr[i][j];

                            }
                        }



                        break;
                    }
                    case 2:
                    {
                        for (int i = 0; i < sizeX; i++) {
                            vect[i] = rand() % 50 + 1;
                        }
                        cout << "Vector Created" << endl;

                        for (int i = 0; i < sizeX; i++) {
                            for (int j = 0; j < sizeY; j++) {
                                matr[i][j] = rand() % 50 + 1;
                            }
                        }
                        cout << "Matrix Created" << endl;

                        break;

                    }
                    default: cout << "The Entered Value is invalid !" << endl;
                }
                bool flag = true;
                while (flag) {
                    cout << "\nChoose : \n\t1 to display the vector\n\t2 to display the matrix\n\t3 to calculate vector X matrix and print result\n\t4 to Exit" << endl;

                    int choose2;
                    cin >> choose2;
                    switch (choose2) {
                        case 1:
                        {
                            cout << "The Vector = [";
                            for (int i = 0; i < sizeX; i++) {
                                cout << vect[i];
                                if (i + 1 == sizeX)
                                    break;
                                cout << ",";
                            }
                            cout << "]";

                            break;

                        }

                        case 2:
                        {

                            cout << "The  Matrix \n";
                            for (int i = 0; i < sizeX; i++) {

                                for (int j = 0; j < sizeY; j++) {

                                    cout << matr[i][j];
                                    if (j + 1 == sizeY)
                                        break;
                                    cout << " , ";

                                }
                                cout << "\n";
                            }

                            break;

                        }
                        case 3:
                        {

                            for (int i = 0; i < sizeY; i++) {
                                for (int j = 0; j < sizeX; j++) {
                                    multblication[i] += vect[j] * matr[j][i];
                                }
                            }

                            cout << "Vector X Matrix Result = [";
                            for (int i = 0; i < sizeY; i++) {
                                cout << multblication[i];
                                if (i + 1 == sizeY)
                                    break;
                                cout << ",";
                            }
                            cout << "]";

                            break;

                        }
                        case 4:
                        {
                            flag = false;
                            break;

                        }
                        default: cout << "The Entered Value is invalid !" << endl;

                    }

                }

                break;
            }
            case 2:
            {
                int M;
                int L;
                int N;
                cout << "Enter first matrix Dimensions M X N : " << endl;
                cout << "Enter M : ";
                cin >> M;
                cout << "\nEnter N : ";
                cin >> N;
                cout << "\nEnter Second matrix Dimensions " << N << " X L: " << endl;
                cout << "Enter L : ";
                cin >> L;
                int first [M][N];
                int secound [N][L];
                int multblication [M][L];
                cout << "Enter\n\t1 to fill the two matrices\n\t2 to fill them randomly"<<endl;
                int entery;
                cin >> entery;
                switch (entery) {
                    case 1:
                    {

                        cout << "\nFill the matrix A " << M << " X " << N << " row by row : " << endl;
                        for (int i = 0; i < M; i++) {
                            for (int j = 0; j < N; j++) {
                                cout << "Matrix A[" << i << "][" << j << "] = ";
                                cin >> first[i][j];

                            }
                        }
                        cout << "\nFill the matrix B " << N << " X " << L << " row by row : " << endl;
                        for (int i = 0; i < N; i++) {
                            for (int j = 0; j < L; j++) {
                                cout << "Matrix B[" << i << "][" << j << "] = ";
                                cin >> secound[i][j];

                            }
                        }


                        break;
                    }
                    case 2:
                    {

                        for (int i = 0; i < M; i++) {
                            for (int j = 0; j < N; j++) {
                                first[i][j] = rand() % 50 + 1;
                            }
                        }
                        cout << "Matrix A Created" << endl;
                        for (int i = 0; i < N; i++) {
                            for (int j = 0; j < L; j++) {
                                secound[i][j] = rand() % 50 + 1;
                            }
                        }
                        cout << "Matrix B Created" << endl;



                        break;
                    }
                    default: cout << "The Entered Value is invalid !" << endl;
                }

                bool multFlag = true;
                while (multFlag) {
                    cout << "\nChoose : \n\t1 to display the matrix A\n\t2 to display the matrix B\n\t3 to calculate matrix A X matrix B and print result\n\t4 to Exit" << endl;
                    int entery;
                    cin >> entery;
                    switch (entery) {

                        case 1:
                        {

                            cout << "The  Matrix A " << M << " X " << N << "\n";
                            for (int i = 0; i < M; i++) {

                                for (int j = 0; j < N; j++) {

                                    cout << first[i][j];
                                    if (j + 1 == N)
                                        break;
                                    cout << " , ";

                                }
                                cout << "\n";
                            }
                            break;

                        }
                        case 2:
                        {

                            cout << "The  Matrix B " << N << " X " << L << "\n";
                            for (int i = 0; i < N; i++) {

                                for (int j = 0; j < L; j++) {

                                    cout << secound[i][j];
                                    if (j + 1 == L)
                                        break;
                                    cout << " , ";

                                }
                                cout << "\n";
                            }
                            break;


                        }
                        case 3:
                        {

                            for (int i = 0; i < M; i++) {
                                for (int j = 0; j < N; j++) {
                                    multblication[i][j] = 0;
                                    for (int k = 0; k < L; k++) {
                                        multblication[i][j] += first[i][k] * secound[k][j];
                                    }
                                }

                            }

                            cout << "Matrix Result A X B is :" << endl;
                            for (int i = 0; i < M; i++) {
                                for (int j = 0; j < L; j++) {
                                    cout << multblication[i][j];
                                    if (j + 1 == L)
                                        break;
                                    cout << " , ";
                                }
                                cout << "\n";

                            }


                            break;

                        }
                        case 4:
                        {

                            multFlag = false;
                            break;
                        }
                        default: cout << "The Entered Value is invalid !" << endl;

                    }
                    break;

                }
                
                break ; 
            }

            case 3:
            {

                
                

                break;

            }
            case 4:
            {
                Bflag = false;
                break;
            }
            default: cout << "The Entered Value is invalid !" << endl;

        }
    }

    return 0;
}

