//
// Created by ByteZip on 28/07/2025.
//
//
#include <iostream>
using namespace std;

/*
 * Function Pointer Arrays
 *  An array of functions(Function Pointers)
*/
int(*ptrOperators) (int a, int b);

//Function prototypes-Convention for functions
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}

int main()
{
    int a, b;
    int result;
    char operation_code;
    int(*Operations []) (int a, int b) ={
        add,subtract,multiply,divide
    };

    cout<<"Enter the first number" << endl;
    cin >> a ;
    cout<<"Enter the second number" << endl;
    cin >> b ;

    cout << "What operation do you want to perform?" << endl;
    cin >> operation_code;

    if(operation_code == '+')
    {
        result =Operations[0] (a, b);
        cout<< result << endl;
    }
    else if(operation_code == '-')
    {
        result =Operations[1](a, b);
        cout<< result << endl;
    }
    else if(operation_code == '*')
    {
        result =Operations[2] (a, b);
        cout<< result << endl;
    }
    else if(operation_code == '/')
    {
        result=Operations[3](a, b);
        cout << result << endl;
    }
    else
    {
        cout<<"Invalid operation code"<<endl;
    }

    cout << "Thank you!" << endl;
    return 0;
}
