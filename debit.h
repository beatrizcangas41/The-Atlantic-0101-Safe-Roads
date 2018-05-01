#ifndef DEBIT_H
#define DEBIT_H
#include <iostream>
using namespace std;
class Debit
{
public:
    Debit();
    ~Debit();
    void print();
    static void test();
    void enterCreditCard();
    
    
private:
    string debitCardNumber;
    string nameOnCard;
    int securityCode;
    string expirationDate1;
    string expirationDate2;
    
};

#endif // DEBIT_H
