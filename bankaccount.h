#include <iostream>
using namespace std;
#include <fstream>
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
//    void setBankAccount();
//    void getBankAccount();

    void setBalance(double balance);
    double getBalance();
    void setRoutingNumber(string routingNumber);
    string getRoutingNumber();
    void setAccountNumber(string accountNumber);
    string getAccountNumber();

    void saveFile(string fileName);
    bool loadFile(string fileName);
    void print();
    void static test();
};
#endif
