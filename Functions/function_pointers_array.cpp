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
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Creating like a type for this pointer

typedef double(*mathOperations) (double a, double b);

int main()
{
    double a, b;
    double result;
    char operation_code;

    mathOperations operationsFunc[] ={
        add,subtract,multiply,divide
    };
    // int(*Operations []) (int a, int b) ={
    //     add,subtract,multiply,divide
    // };
    cout<<"Enter the first number" << endl;
    cin >> a ;
    cout<<"Enter the second number" << endl;
    cin >> b ;

    cout << "What operation do you want to perform?" << endl;
    cin >> operation_code;

    if(operation_code == '+')
    {
        result =(*operationsFunc) (a, b);
        cout<< result << endl;
    }
    else if(operation_code == '-')
    {
        result =(*(operationsFunc+1))(a, b);
        cout<< result << endl;
    }
    else if(operation_code == '*')
    {
        result =(*(operationsFunc+2))(a, b);
        cout<< result << endl;
    }
    else if(operation_code == '/')
    {
        result=(*(operationsFunc+3))(a, b);
        cout << result << endl;
    }
    else
    {
        cout<<"Invalid operation code"<<endl;
    }

    cout << "Thank you!" << endl;
    return 0;
}

// Function Definitions
double add(double a, double b)
{
    return a + b;
}
double subtract(double a, double b)
{
    return a - b;
}
double multiply(double a, double b)
{
    return a * b;
}
double divide(double a, double b)
{
    if (b == 0)
    {
        cout<< "A number may not be divided by zero!";
        return 0;
    }
    return a / b;
}