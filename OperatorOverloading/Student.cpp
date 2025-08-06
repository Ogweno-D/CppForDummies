//
// Created by Ogweno on 04/08/2025.
//

#include <iosfwd>
#include <iostream>
#include <ostream>
using namespace  std;


class Student
{
    public:
    Student():studentID(),age(){}
    // Constructor with initializer list
    Student(int* id, int* age):studentID(id),age(age){}
    // Student(int &id, int &age):studentID(&id),age(&age) {}
    // Copy constructor
    Student(Student& student)
    {
        studentID = student.studentID;
        age = student.age;

        cout <<"Copy constructor is called" << endl;
    }
    // Assignment Operator
    Student& operator=(const Student& rhs)
    {
        cout << "Assignment operator is called" << endl;
        if (this !=&rhs)
        {
            studentID= rhs.studentID;
            age = rhs.age;
        }
        return *this;
    }
    ~Student()
    {
        cout <<"Destructor is called" << endl;
        delete studentID;
        delete age;
        studentID = nullptr;
        age = nullptr;
    }

    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);

    //Getters and setters
    void setStudentID(int* id) { studentID = id; }
    int getStudentID() const { return *studentID; }

    void setAge(int* a) { age = a; }
    int getAge() const { return *age; }

private:
    int* studentID = new int(0);
    int* age = new int(0);
};
ostream& operator<<(ostream& os, const Student& s)
{
    os<<"StudentID:"<< *s.studentID<< endl;
    os<<"Student Age:"<< *s.age<<endl;
    return os;
}
istream& operator>>(istream& is,Student& s)
{
    cout << "Enter Student ID: " << endl;
    is >> *s.studentID;
    return is;
}
int main()
{
    int id = 20;
    int age = 30;

    Student s1(&id, &age);
    Student s2 = s1;

    Student s3(&id,&age);
    s3=s1;

    auto* s4 = new Student();
    *s4 = s3;
    cout << *s4 << endl;
    s4->setStudentID(&age);
    cout << *s4 << endl;
    delete s4;
    s4=nullptr;


    // cout<<s3<<endl;
    // cin >>  s1;
    // cout << s1;

    return 0;
}