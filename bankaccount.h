#include <iostream>
using namespace std;

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#define MAX_SPACE 50

class BankAccount
{

private:
    double balance;
    string routingNumber;
    string accountNumber;

public:
    BankAccount();

    void linkAccount();
    void deposit();
    void withdraw();
    void print();
    void static test();
};
#endif