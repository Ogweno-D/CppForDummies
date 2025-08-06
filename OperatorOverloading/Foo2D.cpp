//
// Created by DO on 01/08/2025.

#include<iostream>
using namespace  std;

class Foo2D
{
    public:
        //Default Constructor
        Foo2D() : p(nullptr)
        {
            rows = 0;
            cols = 0;
        }
        // Constructor
        Foo2D(int r, int c)
            :rows(r), cols(c), p(new int*[rows])
        {
            // rows = r; cols = c;
            // p = new int*[rows];

            // Each row should have columns
            for(int i=0;i<rows;i++)
            {
                p[i]= new int [cols];
            }

        }
        ~Foo2D()
        {

            // Delete the array of columns for each row
            for(int i=0;i<rows;i++)
            {
                delete []p[i];
            }
            // Delete the row pointers
            delete []p;

            // To prevent dangling pointers
            p=nullptr;
            cout << "Destructor called." << endl;
        }

        // Copy constructor
        Foo2D(const Foo2D& rhs)
        {
            // Copy the dimensions
            rows = rhs.rows;
            cols = rhs.cols;

            // Allocate new memory for the copy
            p = new int*[rows];
            for(int i=0;i<rows;i++)
                {
                    p[i]= new int [cols];
                }
            // Copy the contents
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    p[i][j]=rhs.p[i][j];
                }
            }
            cout << "Copy constructor called." << endl;
        }
        // Assignment Operator
        Foo2D& operator=(const Foo2D& rhs)
        {
            if (this != &rhs) // To prevent self assignment
            {
                // Delete the current object.
                // Starting with the cols
                for (int i = 0; i < rows; i++)
                {
                    delete []p[i];
                }
                delete[] p;

                rows = 0;
                cols = 0;
                p= nullptr;

                // Get the rows & cols from the rhs object
                cols = rhs.cols;
                rows = rhs.rows;

                // Allocate new memory
                p = new int*[rows];
                for (int i = 0; i < rows; i++)
                {
                    p[i] = new int[cols];
                }

                // Deep copy
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        p[i][j] = rhs.p[i][j];
                    }
                }
                cout << "Assignment constructor called." << endl;
            }
            return *this;
        }

        int getRows() const {
            return rows;
        }
        int getCols() const {
            return  cols;
        }

    void set(int r, int c, int value) const
        {
            if (r >= 0 && c >= 0 && r < rows && c < cols)
            {
                p[r][c] = value;
            }
        }
    int getValue(int r, int c) const
        {
            if (r>=0 && c>=0 && r<rows && c<cols)
            {
                return p[r][c];
            }
            cout << "Value is out of range." << endl;
            return -1;
        }
    void print()
        {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<p[i][j]<<" ";
            }
            cout<<endl;

        }
    }

    void setValue( int value)
        {
            for(int i=0;i<rows;i++)
            {
               for (int j=0;j<cols;j++)
               {
                   p[i][j] = value;
               }
            }
        }

private:
    int rows;
    int cols;
    int**p; // 2D Array(Double Pointer)
};

int main()
{
    Foo2D arr1(2, 4);
    Foo2D arr2(4,6);

    arr1.setValue(3);
    arr2.setValue(2);

    // for(int i=0;i<arr1.getRows();i++){
    //     for(int j=0;j<arr1.getCols();j++){
    //         arr1.set(i,j,i*3+j);
    //     }
    // }
    //
    // for(int i = 0; i < arr2.getRows(); i++)
    // {
    //     for(int j = 0; j < arr2.getCols(); j++)
    //     {
    //         arr2.set(i, j, 100 + i * 10 + j);
    //     }
    // }

    // arr2.print();
    // arr1=arr2;

    cout <<"Array 1" << endl;
    arr1.print();
    cout <<"Array 2" << endl;
    arr2.print();



    //
    return 0;
}