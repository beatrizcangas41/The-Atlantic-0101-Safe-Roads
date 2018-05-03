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
        string phoneNumber); // creates a account by using a phonenumber
    int options();
    void transaction(int choice);
    // int requestRide(Location* location, int uberID);
    void saveFile(string fileName);
    bool loadFile(string fileName);
    void process();
    void print();
    static void test();

private:
    // int location;

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
