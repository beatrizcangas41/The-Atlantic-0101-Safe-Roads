#ifndef DEBIT_H
#define DEBIT_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Debit
{
public:
    Debit();
    ~Debit();
    void print();
    static void test();

    void saveFile(ofstream* off);
    Debit* loadFile(ifstream* in);

    void setDebitCardNumber(string debitCardNumber);
    string getDebitCardNumber();
    void setFirstName(string firstName);
    string getFirstName();
    void setLastName(string lastName);
    string getLastName();
    void setMonth(int month);
    int getMonth();
    void setYear(int year);
    int getYear();
    void setSecurityCode(string securityCode);
    string getSecurityCode();

    void enterCreditCard();

private:
    string debitCardNumber;
    string firstName;
    string lastName;
    int month;
    int year;
    string securityCode;
};

#endif // DEBIT_H
