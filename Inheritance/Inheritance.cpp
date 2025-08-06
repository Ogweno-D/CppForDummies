#include <iostream>
//
// Created by DO on 04/08/2025.
//
// #include "Vehicle.h"
using namespace  std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a vehicle" << endl;
    };
    // int c = 0;
    //
    // Vehicle(){fuelAmount=0; miles =0;};
    // //
    // Vehicle(int fuelAmount, int miles)
    // {
    //     this->fuelAmount = fuelAmount;
    //     this->miles = miles;
    // }
    // int  checkFuel( int tankCapacity) const {
    //
    //     return tankCapacity - this->fuelAmount;
    // }


// private:
//     int fuelAmount = 0;
//     int miles = 0;
};
class FourWheel : public Vehicle
{
    public:
    FourWheel()
    {
        cout << "This vehicle has four wheels" << endl;
    }

};
class Car: public FourWheel
{
//     public:
//     Car(int capacity){this->capacity= capacity;};
//
// private:
//     int capacity =0;

};

// Multipath inheritance
// A class is derived from two base classes which are derived fram a single class
class A
{
    public:
    int a;
};
class B: virtual  public  A
{
    public:
    int b;
};
class C: virtual public A
{
    public:
    int c;
};
class D : public  B, public C
{
    public:
    int d;
};
/// Inheritance::Full Example
/// Consider an Employee(can be a lawyer, programmer, accountant) of the company
/// Base Class(Employee)
/// Derived Classes (Lawyer,Accountant,Programmer)
/// The employee class will have virtual functions and itself it will be a virtual base class
/// Add some function overriding in the derived classes.
///
class Employee
{
    public:
    Employee(){};
    Employee(int employeeId,int yearsWorked)
    {
        this->employeeId = employeeId;
        this->yearsWorked = yearsWorked;
    }
    virtual ~Employee() = default;

    // Member methods
    /// Getters
    int getEmployeeId() const
    {
        return this->employeeId;
    }
    int getYearsWorked() const
    {
        return this->yearsWorked;
    }
    /// Setters
    void setEmployeeId(int employeeId)
    {
        this->employeeId = employeeId;
    }
    void setYearsWorked(int yearsWorked)
    {
        this->yearsWorked = yearsWorked;
    }

    /// Abstract Method(pure virtual function)
    /// Every subclass must implement it
    /// It is set to null(0)
    virtual void work() = 0;

private:
    int employeeId = 0;
    int yearsWorked = 0;
};
class Lawyer: public Employee
{
    public:
    Lawyer(){}
    Lawyer(int cases,int employeeId, int yearsWorked)
            :Employee(employeeId,yearsWorked), casesWorked(cases){}

    int getCasesWorked() const
    {
        return this->casesWorked;
    };
    void setCasesWorked(int casesWorked)
    {
        this->casesWorked = casesWorked;
    }
    void work() override
    {
        cout << "The lawyer is working!" << endl;
    };

private:
    int casesWorked = 0;
    int employeeId = 0;
    int yearsWorked = 0;

};
/// Multiple Inheritance
///
///
///

class Animal{

    public:
    virtual void print()
    {
        cout << "The animal is called" << endl;
    }

};
class Mammal : public  Animal
{
    public:
    void print()
    {
        cout << "The mammal is called" <<endl;
    }
};
class Bird : public  Animal
{
    public:
    void print()
    {
        cout << "The Bird is called" <<endl;
    }
};
class Bat : public  Bird, public  Mammal
{
public:

    void fly()
    {
        cout <<"The Bat is flying" <<endl;
    }
    void print()
    {
        Mammal::print();
        cout << "The Bat is called" <<endl;
    }
};


// All the concepts together
class Progression
{
    public:
    Progression():first(0),curr(0){}
    explicit Progression(long f=0):first(f),curr(f){}
    virtual ~Progression()
    {
        cout << "The destructor is called" << endl;
    };

    void printProgression(int n);

protected:
    virtual long firstValue();
    virtual  long nextValue();

    // Our variables
    long first = 0;
    long curr = 0;
};
void Progression::printProgression(int n)
{
    cout << firstValue() << endl;

    for (int i = 2; i < n; i++)
    {
        cout << ' ' << nextValue();
        cout << endl;
    }

}
long Progression::firstValue()
{
    curr = first;
    return curr;
}
long Progression::nextValue()
{
    curr = curr + 1;
    return curr;
}
class ArithmeticProgression : public  Progression
{
    public:
    ArithmeticProgression(long i):Progression(i),inc(i){}
    long nextValue() override
    {
        curr +=inc;
        return curr;
    };
protected:

    long inc;
};
class GeometricProgression: public Progression
{
    public:
        GeometricProgression(long b=3):Progression(1), base(b){}
        long nextValue() override
        {
            curr*=base;
            return curr;
        }
    protected:
        long base;
};
class FibonacciProgression:public Progression
{
public:
    FibonacciProgression(long f=0,long p=1):Progression(f),second(p),prev(second-first){}


protected:
    long second;
    long prev;

    virtual  long firstValue()
    {
        curr= first;
        prev = second-first;
        return curr;
    };
    virtual  long nextValue()
    {
        long temp = curr;
        prev = curr;
        curr+=temp;
        return curr;
    };
};

int main()
{
    /// Progessions
    // Progression* prog;
    // prog = new ArithmeticProgression(2);
    // prog->printProgression(10);
    // delete prog;
    //
    // prog = new GeometricProgression(6);
    // prog->printProgression(10);
    // delete prog;
    //
    // prog = new FibonacciProgression(3,4);
    // prog->printProgression(10);
    // delete prog;


    // Multiple inheritance
    // Why is there an error on the dynamic cast?
    Bird* bat = new Bat;
    dynamic_cast<Bat*>(bat)->fly();
    delete bat;



    // Employee* employeeLawyer = new Lawyer();
    // employeeLawyer->work();
    // employeeLawyer->setEmployeeId(12);
    // employeeLawyer->setYearsWorked(30);
    // cout << employeeLawyer->getEmployeeId() << endl;
    // cout << employeeLawyer->getYearsWorked() << endl;
    // delete employeeLawyer;
    //
    //
    // Lawyer dennis(12,123,10);
    // dennis.work();
    // cout << "Cases worked: " <<dennis.getCasesWorked() << endl;
    // cout << "EmployeeId: " << dennis.getEmployeeId() << endl;
    // cout << "YearsWorked: " << dennis.getYearsWorked() << endl;
    //
    // auto* paul = new Lawyer(5,231,10);
    // cout << "\n===================\n" << endl;
    // paul->work();
    // cout << "Cases worked: " << paul->getCasesWorked() << endl;
    // cout << "EmployeeId: " << paul->getEmployeeId() << endl;
    // cout << "YearsWorked: " << paul->getYearsWorked() << endl;
    // delete paul;
    // paul = nullptr;


    // D obj;
    // obj.a =100;
    // obj.a=200;
    //
    // cout<< "A : " << obj.a << endl;
    // Car salon(2);
    // int p = salon.c = 23;
    //
    // cout<< salon.checkFuel(12) << endl;
    // cout << p << endl;
    // Car salon;

    return  0;
}

