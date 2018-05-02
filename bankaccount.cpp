#include "bankaccount.h"

BankAccount::BankAccount()
{

    this->balance = 0.0;
    this->routingNumber = 0.0;
    this->accountNumber = 0.0;
}

void BankAccount::linkAccount()
{
    cout << "enter your routing number" << endl;
    cin >> routingNumber;
    cout << "enter your account number" << endl;
    cin >> accountNumber;
    cout << "checking... checking... Account linked" << endl;
}

void BankAccount::deposit()
{
    cout << "enter balance" << endl;
    double amount = 0.0;

    cin >> amount;
    balance += amount;
}
void BankAccount::withdraw()
{
    cout << " take out amount " << endl;
    double withdraw;
    cin >> withdraw;
    if(balance > withdraw) {
        balance = balance - withdraw;
    } else {
        cout << "not enough money" << endl;
    }
}

void BankAccount::saveFile(string fileName)
{
    ofstream out;
    out.open("BankAccount.txt");
    out << balance << endl;
    out << accountNumber << endl;
    out << routingNumber << endl;
    out.close();
}

void BankAccount::loadFile(string fileName)
{
    ifstream in("BankAccount.txt");
    char line[20];
    if(in.is_open()) {

        in >> line;
        cout << "Your balance is: " << line << endl;
        in >> line;
        cout << "Your account number is: " << line << endl;
        in >> line;
        cout << "Your account number is: " << line << endl;
    }
    in.close();
}
void BankAccount::print()
{

    cout << "your balance is " << balance << endl;
    cout << "your account number is " << accountNumber << endl;
    cout << "your routing number is " << routingNumber << endl;
}
void BankAccount::test()
{

    BankAccount danny;
    danny.linkAccount();
    danny.deposit();
    danny.withdraw();
    danny.print();
    danny.saveFile("BankAccount.txt");
    cout << "\nTesting loadfile(): " << endl;
    danny.loadFile("BankAccount.txt");
}