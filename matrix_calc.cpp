
/* 
 * File:   main.cpp
 * Author: maxmya
 *
 * Created on 27 February 2016, 14:32
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main() {



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


    return 0;
}

