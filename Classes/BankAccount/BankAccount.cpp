//
// Created by Ogweno on 29/07/2025.
//

#include "BankAccount.h"

#include <iostream>
#include <ostream>
using namespace std;

// int main()
// {
//     BankAccount bank1("Dennis",10000,2000);
//     // bank1.name= "Denis";
//     // bank1.balance = 10000;
//     bank1.withdraw(100);
// }

// Implementations
// Constructor
 BankAccount::BankAccount(string name, int bankNumber, double balance)
{
    this->name = std::move(name);
    this->bankNumber = bankNumber;
    this->balance = balance;
}


// Functions
void BankAccount::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
    }
    double rem = balance- amount;
    cout << " Name: " << name << endl;
    cout << "Current amount: " << rem << endl;
}
