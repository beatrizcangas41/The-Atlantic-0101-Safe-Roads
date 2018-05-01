#include "debit.h"

Debit::Debit()
{
}

Debit::~Debit()
{
}
void Debit::print()
{
    cout << nameOnCard << endl;
    cout <<debitCardNumber<<endl;

}
void Debit::test()
{
    Debit Card;
    Card.enterCreditCard();
    Card.print();
}

void Debit::enterCreditCard()
{
    cout << " enter credit card information " << endl;
    cout << "Card Number ";
    cin >> debitCardNumber ;
    cout << " enter name on card ";
    cin >> nameOnCard;
    cout <<" enter security code ";
    cin >> securityCode;
    cout << " enter expiration date ";
    cin >> expirationDate1;
    cout << "information is saved."<<endl;
}
