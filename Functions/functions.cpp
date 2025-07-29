//
// Created by Ogweno on 28/07/2025.
//
#include <iostream>
using namespace std;

void display();
void swap(int a, int b);
void swapByReference(int &a, int &b);
inline int factorial(int n);
int factorialRecursive(int n);
void displayName();

int main()
{
    int var = 8;
    int var2 = 10;
    cout << "Before the swap:"<< var << "," <<var2<< endl;
    swap(var, var2);
    cout << "After the swap:"<< var << "," <<var2 << endl;

    cout<< "Swap by reference now:" << endl;
    swapByReference(var, var2);
    cout << "After the swap:"<< var  << "," <<var2<< endl;
    // display();
    factorial(var);
    cout << "Factorial : " <<  factorial(var) << endl;
    // cout << "Recursive factorial : " <<  factorialRecursive(var) << endl;

    return 0;
}
/*
* Swap function
* (pass By Value - The function only swaps copies of the values of
* the variables passed.)
*
*/
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
/*
* Swap function
* (pass By Reference - The actual values of the variables passed are modified)
*
*/
void swapByReference(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
/*
* Simple Function (Ask user to enter their name and it outputs their name to the console)
*/
void display()
{
    char name [20];
    cout << "Enter your name: ";
    cin>> name;
    cout << "I am trying if this will work " << name << endl;
}
/*
 * Factorial function
*/
inline int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

/*
 * Factorial function - for Recursion/Recursive
*/
// int factorialRecursive(int n)
// {
//     return (n<2) ? 1 : n*factorialRecursive(n);
// }

/*
 * Characters manipulation
*/
void displayName()
{
    char name [20];
    cout << "Enter your name: ";
    cin>> name;
    cout << "I am trying if this will work " << name << endl;
}

