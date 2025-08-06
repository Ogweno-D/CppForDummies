//
// Created by Ogweno on 28/07/2025.
//

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    // Definition
    // At its core multidimensional arrays ara just an array of pointers/ pointer of pointers;
    // data_type array_name[size1][size2]...[size N]
    // E.g int two_d[2][3]; [rows][columns]
    // int three_d[2][3][5]
    //
    int numArray[2][3] = {{1,2,3},{4,5,6}};
    size_t numArraySize = sizeof(numArray) / sizeof(numArray[0]);
    cout << "Array size: " << numArraySize << endl;

    cout << numArray[1][2] << endl;
    cout<< "Traversing the arrays using pointers" << endl;
    cout << *(*(numArray+1)+2) << endl;
    cout << "Array elements: " << endl;
    for(int i = 0; i < numArraySize; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << numArray[i][j] << " ";
        }
    }

    // 3D Arrays
    int cubeArray[2][3][4] = {
        {{1,2,3},{2,3,4},{2,3,4}},
        {{2,3,3},{2,4,6},{4,6,7}}
    };

    size_t cubeArraySize = sizeof(cubeArray);

    cout << "\n------------3D Array--------------" <<endl;
    cout << " The size of integer : " << sizeof(int) << endl;
    cout << "Array size: " << cubeArraySize << endl;
    cout << *cubeArray[1][2] << endl;
    cout << "Using pointers \n" << endl;

    cout<< *(*(*cubeArray))<<endl;
    cout << *(*(*(cubeArray+1)+2)) << endl;
    cout<< "This is the end!" << endl;


    // Dynamic 2DArrays
    cout<<"=========================" << endl;
    cout<< " Dynamic 2D Arrays" << endl;
    int rows = 4;
    int cols = 3;

    // This is an array of pointers {Because the rows are arrays(pointers)}
    int** dArray = new int*[rows];

    // For each row pointer { allocate the ints - the actual data }
    for(int i = 0; i < rows; i++)
    {
        dArray[i] = new int[cols];
    }

    // Initialize/ use the array
    int value = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            dArray[i][j] = value;
        }
    }
    // cout << "Dynamic 2D Array:\n";
    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         cout << setw(3) << dArray[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << *(dArray[1]) << endl;

    // Deallocate
    for(int i = 0; i < rows; i++)
    {
        delete[] dArray[i];
    }
    delete[] dArray;
    dArray = nullptr;

    return 0;

 }


