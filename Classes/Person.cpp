//
// Created by Ogweno on 29/07/2025.
//

#include "Person.h"

#include <filesystem>
#include <iostream>
using  namespace  std;


//  Person::Person()
// {
//     this->age = 0;
//     this->marks = 0;
// }

 Person::Person() { age = 0, marks =0; }



 // Person::Person(int age, int marks)
 // {
 //     this->age = age;
 //     this->marks = marks;
 // }

 Person::Person(int age, int marks)
 {
     this->age= age;
     this->marks= marks;
 }


int Person::getAge()
 {
     return this->age;
 }
void Person::setAge(int age)
 {
     this->age = age;
 }
int Person::getMarks()
 {
     return this->marks;
 }
void Person::setMarks(int marks)
 {
     this->marks = marks;
 }


// Pass by Value
void changeAge(Person p)
{
    p.setAge(16);
    p.setMarks(p.getMarks());
    cout << " (*Inside the function) This is the new age: " << p.age << endl;
}
void changeMarks(Person p)
 {
     p.setMarks(120);
     p.setAge(p.getAge());
     cout << " (*Inside the function) The new marks are: " << p.marks << endl;
 }

// Pass by reference
void refChangeAge(Person& p)
 {
     p.setAge(12);
     cout << " (*Inside the function) The new age is: " << p.age << endl;

 }
void refChangeMarks(Person& p)
 {
     p.setMarks(60);
     cout << " (*Inside the function) The new marks are: " << p.marks << endl;
 }

// Pointer
void ptrChangeAge(Person* p)
 {
     p->setAge(30);
     cout << " (*Inside the function) The new age: " << p->age << endl;
 }
void ptrChangeMarks(Person* p)
 {
     p->setMarks(70);
     cout << " (*Inside the function) The new marks are: " << p->marks << endl;
 }

int main(){
     // Person person();
     // person().setAge(20);
     // person().setMarks(200);
     Person person(20,200);
     cout << "Using the parameterized constructor to set the values of the new object" << endl;
     cout << "This person is: " << person.age << " years old!" << endl;
     cout << "This person has: " << person.marks << endl;

     // Pass by value
     cout << " This is pass by value!" << endl;
     changeAge(person);
     changeMarks(person);
     //
     cout << " (*Outside the function) The age  is: " << person.age << endl;
     cout << " (*Outside the function)  The marks are: " << person.age << endl;

     // Pass By Reference
     cout << "\n--------This is pass by reference!-----\n" << endl;
     refChangeAge(person);
     cout << " (*Outside the function) The age is: " << person.age << endl;
     refChangeMarks(person);
     cout << "(*Outside the function) The marks are: " << person.marks << endl;

     // Using pointers
     cout << "\n--------using pointers----------\n" << endl;
     ptrChangeAge(&person);
     cout << " (*Outside the function) The age  is: " << person.age << endl;
     ptrChangeMarks(&person);
     cout << " (*Outside the function) The marks are: " << person.marks << endl;

 }