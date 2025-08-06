#include <iostream>
#include<vector>

using namespace std;

 class  Foo
 {
     public:
        // Default Constructor
        Foo(){x=0,y=0;};
        // Constructor!
        Foo(int x,int y){this->x=x;this->y=y;};
        void set_all(int a, int b)
        {
            x = a;
            y = b;
        }
        friend int sumA(int a, int b);
        // Takes an object of Class Foo
        // Passes an object to the function
        friend int sum(Foo);

     private:
        int x = 0;
        int y = 0;
 };

// Friend function-defined outside the scope of the class::
int sumA(int a, int b)
{
    return a+b;
}

int sum(Foo foo)
{
    // Pointer to x
    int Foo::*px=&Foo::x;
    int Foo::*py=&Foo::y;
    Foo* fp = &foo;
    int sum = fp->*(px) + foo.*py;
    return sum;
}


int main()
{
    Foo foo(20,30);
    int result = sum(foo);

    cout<< result << endl;

    return 0;

}






// int main()
// {
//     /*
//     int sales = 95000;
//     double stateTax = 0.03 * sales;
//     double countyTax = 0.02 * sales;
//     double totalTax = stateTax + countyTax;
//     double totalEarnings = sales - totalTax;
//
//     cout << "Sales = $" << sales << endl
//         << "State Tax = $" << stateTax << endl
//         << "County Tax = $"<< countyTax << endl
//         << "Total Tax = $" << totalTax << endl
//         << "Total Earnings = $" << totalEarnings << endl
//          << endl;
//
//
//         cout << "Size of char : " << sizeof(char) << endl;
//         cout << "Size of int : " << sizeof(int) << endl;
//         cout << "Size of short int : " << sizeof(short int) << endl;
//         cout << "Size of long int : " << sizeof(long int) << endl;
//         cout << "Size of float : " << sizeof(float) << endl;
//         cout << "Size of double : " << sizeof(double) << endl;
//         cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
//
//         return 0;
//
//     Taking input from the user
//     char name [50];
//     cout << "Enter your name: ";
//     cin.getline(name, 50);
//     // cin >> name;
//     cout << "Hello " << name << "\n";
//
//     int var = 3000;
//
//     // Address of var
//     const int* ptr = &var;
//
//     // Take the value at ptr
//     const int val = *ptr;
//     cout << var << endl;
//     cout << val << endl;
//     cout << ptr << endl;
//
//     POINTERS
//     int values [] = { 10, 0, 12,-4};
//      constexpr int NUM_VALUES = std::size(values);
//
//     std::vector<int*> pointers;
//     std::vector<int**> pointersToPointer;
//     std::cout << " This is the maximum size that can be allocated in the memory for this application " << pointers.max_size() << std::endl;
//     pointers.reserve(NUM_VALUES);
//     std::cout << "Maximum size for this is " << pointersToPointer.max_size() << std::endl;
//     pointersToPointer.reserve(pointers.size());
//
//     for (int& element : values)
//     {
//         pointers.push_back(&element);
//     }
//
//     // For PtoP
//     for (int*& element : pointers)
//     {
//         pointersToPointer.push_back(&element);
//     }
//
//     std::cout << " The size of the array is " << pointers.size() << std::endl;
//     std::cout << " This is the address of th array variables" << std::endl;
//     for (const auto & pointer : pointers)
//     {
//         std::cout << pointer << std::endl;
//     }
//
//     std::cout << "The address of the pointers for the variables " << std::endl;
//     for (const auto & pointer : pointersToPointer)
//     {
//         std::cout << pointer << std::endl;
//     }
//     //
//     std::cout << "\n Dereferencing pointers in the  vector: \n";
//
//     for (const auto & pointer : pointers)
//     {
//         if (pointer != nullptr)
//         {
//             std::cout << *pointer << std::endl;
//         }
//         else
//         {
//             std::cerr << " NULL pointer" << std::endl;
//         }
//     }
//
//     // Sample pointer
//     constexpr long long trial = 3000000000000;
//     auto* dynamicPtr = new long long(trial);
//     long long* ptr = dynamicPtr;
//
//     std::cout << " The standard malloc for this is " << sizeof(ptr) << std::endl;
//     std::cout << "Address for the trial" << &trial << std::endl;
//     std::cout << *ptr << std::endl;
//
//     // Delete then nullify the pointer to prevent dangling pointers;
//     delete dynamicPtr;
//     dynamicPtr = nullptr;
//
//     std::cin.get();
//     */
//
//     /*
//      *ARRAYS - One dimensional Arrays
//      */
//
//     /*
//     int numArray[] = {1,2,3,4,5,6,7};
//     int multiNumArray[2][3]= {
//         {
//             2, 3, 4
//         },
//         {
//             2, 3, 4
//         }
//     };
//
//     for (int i : numArray)
//     {
//         cout << i << endl;
//     }
//
//     cout<< " Array manipulation using pointers:" << endl;
//
//     cout << *(numArray+2) << endl;
//
//     cout << " For multidimensional Arrays:" << endl;
//     cout << *(*(multiNumArray+1) + 1) << endl;
//     */
//
//     /* Pointers II */
//
//     void *ptr = nullptr;
//     int *iptr = new int[4];
//     int var = 8;
//     *iptr = var;
//     ptr = iptr;
//
//     // cin.get();
//     // LOG(ptr);
//
//     cout << *(static_cast<int*>(iptr)) << endl;
//
//     delete iptr;
//     iptr = nullptr;
// }
