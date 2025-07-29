//
// Created by Ogweno on 28/07/2025.
//

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
 }

