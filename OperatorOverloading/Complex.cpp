//
// Created by Ogweno on 30/07/2025.
//

#include <iostream>
using namespace  std;

class Complex
{
    public:
        Complex();
        Complex(double a, double b);

        // An example of operator overloading!
        Complex operator+(const Complex& other) const;
        Complex operator-(const Complex& other) const;
        Complex operator*(const Complex& other) const;
        Complex operator/(const Complex& other) const;

        //Increment and decrement
        // Prefix
        Complex& operator++();
        Complex& operator--();
        // Postfix
        // ( We add the int as a dummy to differentiate between the two)
        Complex& operator++(int);
        Complex operator--(int);

        // Comparison
        bool operator<(const Complex&  other) const;
        bool operator>(const Complex&  other) const;
        bool operator==(const Complex& other) const;
        bool operator!=(const Complex& other) const;
        bool operator>=(const Complex& other) const;
        bool operator<=(const Complex& other) const;



    // Public getters
    double getReal () const
    {
        return real;
    }
    double getImg () const
    {
        return img;
    }

    // static void sayAge()
    // {
    //     cout<< age << endl;
    // }

    private:
        double real;
        double img;
        // static  int age;
};

Complex::Complex(): real(0.0), img(0.0) {}
Complex::Complex(double a, double b) : real(a), img(b)
{
    real = a;
    img = b;
}
Complex Complex::operator+(const Complex& other) const
{
    Complex temp;
    // this->real+ b.real;
    temp.real = real + other.real;
    temp.img = img + other.img;
    return temp;
}
Complex Complex::operator-(const Complex& other) const
{
    Complex temp;
    // cout << this->real- other.real << endl;
    // temp.real= this-> real - other.real;
    temp.real = real - other.real;
    temp.img = img - other.img;
    return temp;
}
Complex Complex::operator*(const Complex& other) const
{
    Complex temp;
    temp.real= real*other.real;
    temp.img= img*other.img;
    return temp;
}
Complex Complex::operator/(const Complex& other) const
{
    Complex temp;
    temp.real= real/other.real;
    temp.img= img/other.img;
    return temp;
}

// Prefix Increment
Complex& Complex::operator++()
{
    real++;
    // img++;
    return *this;
    // return (*this);
}
Complex& Complex::operator--()
{
    real--;
    return *this;
}

// Postfix Increment/Decrement
Complex& Complex::operator++(int)
{
    // Complex temp = *this; // Create a copy(Preserve object stat
    // ++temp; // Normal increment
    // return temp; // Return the preserved copy

    Complex *temp2 =this;
    ++(*temp2);
    cout <<" The increment is happening: " << temp2->getReal() << endl;
    return *temp2; // This one returns a copy before the increment

}
Complex Complex::operator--(int)
{
   Complex temp = *this; // Create a copy
    --temp; // Normal decrement
    cout << "The decrement is happening" << temp.getReal() << endl;
    return temp; // return the copy
}


// Comparison
bool Complex::operator<(const Complex& other) const
{
    return (this->real < other.real || this->img < other.img);
}
bool Complex::operator>(const Complex& other) const
{
    return (this->real > other.real && this->img > other.img);
}
bool Complex::operator==(const Complex& other) const
{
    return (this->real == other.real && this->img == other.img);
}
bool Complex::operator!=(const Complex& other) const
{
    // return (this->real != other.real && this->img != other.img);
    return !(*this==other);
}
bool Complex::operator>=(const Complex& other) const
{
    return (this->real >= other.real && this->img >= other.img);
}
bool Complex::operator<=(const Complex& other) const
{
    // return (this->real <= other.real && this->img <= other.img);
    // The rule of contrariety
    return !(*this >= other);
}

int main()
{
    Complex c1(2,5);
    Complex c2(3,4);

    // Prefix Increment
    // The value of the object incremented is changed forever.-No backsies!!
    Complex c1_prefix= ++(++c1); // Expected 2+1=3 (for single increment) and 4 for double increment
    cout << c1_prefix.getReal() << endl;

    // Prefix Decrement
    auto* c1_prefix_decrement = new Complex;
    *c1_prefix_decrement = --(--c1);
    cout << c1_prefix_decrement->getReal() << endl; // Expected 4-1 = 3 & 3-1=2 Got 2 and 1 respectively
    delete c1_prefix_decrement;


    // Refresh c1 for the operations
    c1 = Complex(2,5);
    //Postfix Increment
    auto* c1_postfix = new Complex;
    *c1_postfix = (c1++)++;
    cout <<" After postfix increment: "<< c1_postfix->getReal() << endl; // Expected just c1.real = 2
    delete c1_postfix;

    //Postfix Decrement
    auto* c1_postfix_decrement = new Complex;
    *c1_postfix_decrement =(c1--)--;
    cout <<" After postfix decrement: "<< c1_postfix_decrement->getReal() << endl;
    delete c1_postfix_decrement;

    // auto*c = new Complex();
    // *c = Complex(1,2);
    // delete c;

    // Complex::sayAge();

    // We are adding the two objects
    // Assigning it to the new object c3

    // Addition
    // Complex c3 = c1 + c2;
    // cout << c3.getImg() << ","<<c3.getReal() <<  endl;
    //
    // // Subtraction
    // Complex c4 = c1 - c2;
    // cout << c4.getImg()<< "," <<c4.getReal() <<  endl;
    //
    // // Multiplication
    // Complex c5 = c1 * c2;
    // cout << c5.getImg() << ","<<c5.getReal() <<  endl;
    //
    // // Division
    // Complex c6 = c1 / c2;
    // cout << c6.getImg() << "," <<c6.getReal() <<  endl;
    //
    // // Comparison
    // // <
    // bool isLessThan = c1 < c2;
    // cout << isLessThan << endl;
    //
    // //isGreaterThan
    // bool isGreaterThan = c1 > c2;
    // cout << isGreaterThan << endl;
    //
    // // IsEqual
    // bool isEqual = c1 == c2;
    // cout << isEqual << endl;
    //
    // //IsNot Equal
    // bool isNotEqual = c1 != c2;
    // cout << isNotEqual << endl;
    //
    //
    // // isGreaterThanOrEqual
    // bool isGreaterThanOrEqual = c1 >= c2;
    // cout << isGreaterThanOrEqual << endl;
    //
    // // isLessThanOrEqual
    // bool isLessThanOrEqual = c1 <= c2;
    // cout << isLessThanOrEqual << endl;

    return 0;
}



