#ifndef UBER_H
#define UBER_H
#include "bankaccount.h"
#include "debit.h"
#include <iostream>
#include <fstream>
using namespace std;
class Uber
{
public:
    Uber();
    ~Uber();

    void createAccount(string email,
        string firstName,
        string lastName,
        string phoneNumber); 
    int options();
    void transaction(int choice);
    int requestRide(Location* location);
    void saveFile(string fileName);
    bool loadFile(string fileName);
    void process();
    void print();
    static void test();

private:
    
    
    string email;
    string password;
    string firstName;
    string lastName;
    string phoneNumber;
    int choice;
    BankAccount* pBankAccount;
    Debit* pDebitCard;
};
// aggregation relationship of bank account.
#endif
