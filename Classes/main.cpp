//
// Created by Ogweno on 29/07/2025.

#include <iostream>
#include <ostream>

#include "Animal/Animal.h"
#include "BankAccount/BankAccount.h"

using namespace std;

int main()
{


    BankAccount bank2("Dennis",12342, 2000.00);
    bank2.withdraw(200.00 );
    BankAccount::increaseCounter();
    bank2.increaseCounter();

    // Learnt something new here
    // -> single quote char literals are of an integer type

    Animal dog("Dog","Barkss!!",2.5);
    cout << " This is a "<< dog.name<< endl;
    dog.sound();
    // dog.currWeight(dog.weight);

    // Cat
    Animal cat("Dog","Purrrrrs",2.5);
    cout << " This is a "<< dog.name<< endl;
    cat.sound();

    // Cow
    Animal cow("Dog","Mooooh!", 90);
    cout << " This is a "<< dog.name<< endl;
    cow.sound();


}