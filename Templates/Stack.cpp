//
// Created by DO on 06/08/2025.
//

// #include "Stack.h"
#include <iostream>
using namespace  std;


template <class T>
class Stack
{

public:
    explicit Stack(int const top=-1):top(top){};
    ~Stack()
        {
            cout <<"The stack is destroyed" << endl;
        }
    void push(T var)
    {
        // Increment the index = store the value there
            // (-1+1=0)
        st[++top] = var;
    }
    T pop()
    {
        return st[top--];
    }
    void display()
    {
        for (int i = 0; i < top+1 ; i++)
        {
            std::cout << st[i] << " " << endl;
        }
    }

private:
    T st[10];
    int top;
};


int main()
{
    Stack<char> stack;
    stack.push('w');
    stack.push('e');
    stack.push('n');
    stack.push('d');
    stack.push('y');

    stack.display();
}