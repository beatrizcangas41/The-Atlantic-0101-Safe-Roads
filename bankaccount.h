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
    string filename;

public:
    BankAccount();

    void linkAccount();
    void deposit();
    void withdraw();
    void setBankAccount();
    void getBankAccount();
    void saveFile(string fileName);
    void loadFile(string fileName);
    void print();
    void static test();
};
#endif