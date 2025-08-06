//
// Created by Ogweno on 01/08/2025.
//

#include <iostream>

#include <ostream>
using  namespace std;
class Foo
{
public:
    // Default Constructor
    Foo();
    // Constructor
    Foo(int s){size = s;p = new int[size];}
    // Destructor
    ~Foo(){delete[] p;}

    void set_value(int index, int value){p[index]= value;}
    int getValue(int index){return p[index];}
    int getSize(){return size;}
    static void getCounter()
    {
        counter++;
        cout<< " Looping " << counter<< " times " << endl;
    }

    // Copy constructor
    // (Creates a temporary copy of the passed in object)
    Foo(const Foo& rhs)
        {
            size = rhs.size;
            p = new int[size];
            for (int i = 0; i < size; i++)
            {
                p[i] = rhs.p[i];
            }
        }
    Foo& operator=(const Foo& rhs)
        {
            // To prevent assigning to itself
            if(this != &rhs)
            {
                delete[] p;

                //get the size for the rhs
                size = rhs.size;

                // Create a new array using the rhs size
                p = new int[size];

                //Copy the content of the rhs array to the lhs(p)
                for (int i=0; i<size;i++)
                {
                    p[i] = rhs.p[i];
                }
            }
            return *this;

        }

private:
    int* p; // Dynamic array
    int size=0;
    static int counter;
};

int Foo::counter = 0;

int main()
{
    Foo arr1(6), arr2(7), arr3(4);

    // Populate arrays, 1 and 2
    //Array 1
    for (int i = 0; i < arr1.getSize(); i++)
    {
        arr1.set_value(i, i*i);
        Foo::getCounter();
    }
    // Array 2
    for (int i = 0; i < arr2.getSize(); i++)
    {
        arr2.set_value(i, i+3);
    }


    // Try out the assigment
    arr2 = arr3 = arr1;
    for (int i = 0; i < arr1.getSize(); i++)
    {
        cout << arr1.getValue(i) << endl;
    }

    return 0;

}