//
// Created by Ogweno on 29/07/2025.
//

#ifndef PERSON_H
#define PERSON_H

class Person {

    public:
        int age =0;
        int marks=0;

    Person();
    // ~Person();
    Person(int age, int marks);
    // Person(const Person& person);
    // Person& operator=(const Person& person);

    public:
        void setAge(int age);
        void setMarks(int marks);

        int getAge();
        int getMarks();

};



#endif //PERSON_H
