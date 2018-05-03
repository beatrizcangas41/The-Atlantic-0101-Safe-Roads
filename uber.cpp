#include "uber.h"

Uber::Uber()
{
    pBankAccount = 0;
    pDebitCard = 0;
    choice = 0;
}

Uber::~Uber()
{
    if(pBankAccount)
        delete pBankAccount;
    pBankAccount = 0;

    if(pDebitCard)
        delete pDebitCard;
    pDebitCard = 0;
}

void Uber::saveFile(string fileName)
{
    ofstream out("uberAccount.txt");
    if(out.is_open()) {
        out << email << endl;
        out << firstName << endl;
        out << lastName << endl;
        out << phoneNumber << endl;
        out << password << endl;
    } else {
        cout << "Could not open file to write" << endl;
    }
    out.close();
}

bool Uber::loadFile(string fileName)
{
    ifstream in("uberAccount.txt");
    char str[10];
    if(in.is_open()) {
        in.getline(str, 100);
        email = str;
        in.getline(str, 100);
        firstName = str;
        in.getline(str, 100);
        lastName = str;
        in.getline(str, 100);
        phoneNumber = str;
        in.getline(str, 100);
        password = str;
        return 1;
    } else {
        cout << "Could not open file to read" << endl;
        return 0;
    }
    return 0;
    in.close();
}

void Uber::createAccount(string email, string firstName, string lastName, string phoneNumber)
{
    this->email = email;
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    cout << "enter password to sign in to account" << endl;
    cin >> password;

    saveFile("uberAccount.txt");
}
int Uber::options()
{
    int decision;
    cout << "enter a choice " << endl;

    cout << "1, enter Bank Account info " << endl;
    cout << "2, enter debit card info " << endl;
    //  cout << " << endl;

    cin >> decision;
    return decision;
}
int Uber::requestRide(Location* location)
{
    cout << " where would you like to go?" cin >> destination;
}

void Uber::print()
{
}
void Uber::process()
{
    int num1, num2, num3, num4;

    num1 = loadFile("uberAccount.txt");
    if(num1 == 0) {
        cout << "creating account" << endl;
        createAccount("gmail", "danny", "rios", "123456789");
    }

    num2 = loadFile("BankAccount.txt");
    num3 = loadFile("DebitCard.txt");
    if(num2 == 0 && num3 == 0) {
        num4 = options();
    }
    if(num4 == 1) {
        requestRide(location * location);
    }
    // check if a uber account exist. if not, createAccount();
    //  createAccount(email, firstName, lastName, phoneNumber);
    // it should save the account
    // choice = options();           // then should check if a bank account or debit card exist.
    // transaction(choice);          // if not, then choose either debit card or bankAccount.
    // then save the file.
    // then call uber with current location, and then direction address.
}
void Uber::test()
{

    Uber me;
    // loadFile("uberAcco")
    // me.account();
    // choice = me.options();
    // me.transaction(choice);
}
