//
// Created by Ogweno on 28/07/2025.
//

#include <iostream>
using namespace  std;

// Function prototype
int sum(int a, int b);

int diff(int a, int b);

// Mystery function prototype
int mystery(int a, int b, bool(*predicate_fn)(int));

bool checkIsEven(int a);

// Typedef function pointer
typedef int(*arithmetic_function)(int, int);
arithmetic_function summation = sum;
arithmetic_function difference = diff;

arithmetic_function conversion(char code)
{
    if (code == '+')
    {
        return &sum;
    }
    if (code == '-')
    {
        return &diff;
    }
    return nullptr;
}

int main()
{
    int x, y;
    char op_code;
    // Declare a function pointer
    // fn(function) points to sum
    // That is it holds the memory address of the functon - sum
    int (*addition)(int x, int y) = sum;
    int (*subtraction)(int x, int y) = diff;

    // Pointer for the checkIsEven function;
    bool(* isEvenChecker)(int) = checkIsEven;

    typedef int (*additionFn)(int x, int y);
    const additionFn additionFunction = sum;

    cout << "Enter the first number" << endl;
    cin >> x;
    cout << "Enter the second number" << endl;
    cin >> y;

    cout<< "The sum is : " << sum(x, y) << endl;
    cout<< "===========================" << endl;
    cout<< "\n Using a function pointer " << endl;
    cout << "The sum is :" << (*addition)(x, y)<< endl;

    cout<<"\n-------------------------------------" << endl;
    cout << "Using typedef for better code" << endl;
    cout << "The sum is :" << (*additionFunction)(x, y) << endl;

    cout << "\n-------------------------------------" << endl;
    cout << "Proper typedef example" << endl;
    cout << "Enter operation code '+' or '-'" << endl;
    cin >> op_code;
    const arithmetic_function selected_op= conversion(op_code);
    cout << "Your result is" << selected_op << endl;
    int u;
    cout << "Enter your Lucky number" << endl;
    cin >> u;
    cout << "The Lucky number is :" << mystery(x,u,isEvenChecker) << endl;



    return 0;
}

int sum(int a, int b)
{
    return a + b;
}

int diff(int a, int b)
{
    return a - b;
}

bool checkIsEven(int a)
{
    if (a % 2 == 0)
    {
        return true;
    }
    return false;
}

/*
 *Mystery function with  function pointer as a parameter
*/
int mystery(int a, int b, bool (*predicate_fn)(int))
{

    if (predicate_fn(a))
    {
        return a + b;
    }

    return 0;
}

/*
 * Convert function
*/

