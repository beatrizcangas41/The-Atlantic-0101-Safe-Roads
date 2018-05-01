#ifndef UBER_H
#define UBER_H
#include <bankaccount.h>
#include <debit.h>
#include <iostream>
using namespace std;
class Uber
{
public:
    Uber();
    ~Uber();
    
    void account(); // creates a account by using a phonenumber
    int options();
    void transaction(int choice);
    //int requestRide(Location* location, int uberID);
    void process();
    void print();
    static void test();

private:
    //int location;
    string email;
    string password;
    double amount;
    int choice;
    BankAccount* Danny;
    Debit* DannysCard;
    
};
// aggregation relationship of bank account.
#endif
