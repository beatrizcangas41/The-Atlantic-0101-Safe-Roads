#include "uber.h"

Uber::Uber()
{
    Danny = new BankAccount;
    DannysCard = new Debit;
}

Uber::~Uber()
{
    if(Danny)
        delete Danny;
    Danny = 0;
    if(DannysCard)
        delete DannysCard;
    DannysCard = 0;
}

int Uber::options()
{
    int decision;
    cout << "enter a choice " << endl;

    cout << "1, enter Bank Account info " << endl;
    cout << "2, enter debit card info" << endl;
    cout << " 3, get uber" << endl;

    cin >> decision;
    return decision;
}
void Uber::transaction(int choice)
{
    switch(choice) {
    case 1: {
        Danny->linkAccount();
        Danny->print();
        break;
    }
    case 2: {
        DannysCard->enterCreditCard();
    } break;
    case 3: {
        // requestRide(Location* location, int uberID);
    }
    }
}

void Uber::account()
{
    do {
        cout << "create for an uber account " << endl;
        cout << "enter email:";
        cin >> email;
        //
        cout << endl;
        cout << "enter password:";
        cin >> password;
        cout << endl;
        cout << "is this correct? 1 for yes, 2 for no" << endl;

        int choice;
        cin >> choice;
    } while(choice == 2);
}

void Uber::print()
{
}
void Uber::process()
{
    account();
    choice = options();
    transaction(choice);
}
void Uber::test()
{
    int choice;

    Uber me;
    me.account();
    choice = me.options();
    me.transaction(choice);
}
