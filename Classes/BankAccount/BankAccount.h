//
// Created by Ogweno on 29/07/2025.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
using  namespace  std;


class BankAccount {
    public:
        string name;
        int bankNumber;
        double balance;

    BankAccount( string name, int bankNumber, double balance );

    // Constructor
    void withdraw(double amount);

};



#endif //BANKACCOUNT_H
