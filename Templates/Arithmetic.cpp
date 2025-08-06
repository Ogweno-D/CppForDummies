//
// Created by DO on 06/08/2025.
//
// #include "Arithmetic.h"
#include <iostream>
// #include <utility>
using namespace std;



// class Library
// {
//     public:
//     Library():str(""),books(){};
//     explicit Library(string& s):str(std::move(s)){};
//
//
// private:
//     string str;
//     char* books[];
// };
class Arithmetic
{
public:
    Arithmetic() : a(0), b(0) {}

    Arithmetic(int x, int y) : a(x), b(y) {}

    // Copy constructor
    // Arithmetic(Arithmetic&other):a(other.a),b(other.b){}
    Arithmetic(const Arithmetic& other)
    {
        a = other.a;
        b = other.b;
    }

    ~Arithmetic() { cout << "The destructor is called " << endl; }
    // Assignment Operator
    Arithmetic& operator=(const Arithmetic& other)
    {
        if (this != &other)
        {
            a = other.a;
            b = other.b;
        }
        return *this;
    }
    Arithmetic& operator+(const Arithmetic& other)
    {
        a += other.a;
        b += other.b;

        return *this;
    }

    friend istream& operator>>(istream& is, Arithmetic& ar);
    friend ostream& operator<<(ostream& os, const Arithmetic& ar);

    void print() const { cout << "These are my variables" << a << "," << b << endl; }

private:
    int a;
    int b;
};
/// Iostream Operator Overloading!
istream& operator>>(istream& is, Arithmetic& ar)
{
    cout << "Enter the object's first variable: ";
    cin >> ar.a;
    cout << "Enter the object's second variable: ";
    cin >> ar.b;

    return is;
}
ostream&operator<<(ostream& os, const Arithmetic& ar)
{
    cout << ar.a << ar.b << endl;
    return os;
}
/// Function Template
///
///  Simple function to get the max between two values
template<typename T> T genericMax(T &a, T &b)
{
    return a > b ? a : b;
}
/// Simpler function template to get the minimum between two values
template<typename T> T genericMin(T &a, T &b)
{
    return a < b ? a : b;
}
// We can leave for the compiler to determine the type
template<typename T> auto addString(T&a, T&b)
{
    return a + b;
}
template<typename T> auto minusString(T a, T b)
{
    return a - b;
}


/// Add any two numbers
///
template<typename T> T genericSum(T&a,T&b)
{
    return a + b;
}

int main()
{
    // Library lib1{};
    // Library lib2{};

    // string first, second;
    // cout << "Enter your first name" << endl;
    // cin >> first;
    // cout << "Enter your second name" << endl;
    // cin >> second;
    //
    // cout << "Your name is : " << addString(first, second) << endl;
    // cout << "Your name is : " << minusString(first,second) << endl;
    // char choice;
    //
    // cout << "Hey! Which additions do you want to do?" << endl;
    // cout << "i= Integer" << endl;
    // cout << "d= Double" << endl;
    // cout << "f= Float" << endl;
    // cout << "c= Char" << endl;
    // cout <<"O = Arithmetic Object" << endl;
    // cin>> choice;
    //
    // if (choice == 'i'|| choice == 'I')
    // {
    //     int num1, num2;
    //     cout << "Enter the first number: ";
    //     cin >> num1;
    //     cout << "Enter the second number: ";
    //     cin >> num2;
    //
    //     cout << "The sum is : " << genericSum(num1, num2) << endl;
    //
    // }
    // else if (choice == 'd'|| choice == 'D')
    // {
    //     double num1, num2;
    //     cout << "Enter the first number: ";
    //     cin >> num1;
    //     cout << "Enter the second number: ";
    //     cin >> num2;
    //     cout << "The sum is : " << genericSum(num1, num2) << endl;
    // }
    // else if (choice == 'f'|| choice == 'F')
    // {
    //     float num1, num2;
    //     cout << "Enter the first number: ";
    //     cin >> num1;
    //     cout << "Enter the second number: ";
    //     cin >> num2;
    //     cout << "The sum is : " << genericSum(num1, num2) << endl;
    // }
    // else if (choice == 'c'|| choice == 'C')
    // {
    //     char char1, char2;
    //     cout << "Enter the first number: ";
    //     cin >> char1;
    //     cout << "Enter the second number: ";
    //     cin >> char2;
    //     cout << "The sum is : " << genericSum(char1, char2) << endl;
    // }
    // else if (choice == 'o'|| choice == 'O')
    // {
    //     auto* a = new Arithmetic();
    //     auto* b = new Arithmetic();
    //     cin >> *a;
    //     cin >> *b;
    //     cout << "The sum is : " << genericSum(*a, *b) << endl;
    //
    //     delete a;
    //     delete b;
    //     a=nullptr;
    //     b=nullptr;
    //
    // }

    // auto * a = new int;
    // auto * b = new int;
    //
    //
    // cout<< " Enter the first number" << endl;
    // cin>> *b;
    // cout << "Enter the second number" << endl;
    // cin>>*a;
    //
    // cout<<"Here is your maximum :" << genericMax(*a,*b)<<endl;
    // cout <<"Here is your minimum :" << genericMin(*a,*b)<<endl;
    //
    // delete a;
    // delete b;

}
