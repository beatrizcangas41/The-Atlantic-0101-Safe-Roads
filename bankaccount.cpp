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

void BankAccount::setBalance(double balance) {
    this->balance = balance;
}

double BankAccount::getBalance() {
    return balance;
}

void BankAccount::setRoutingNumber(string routingNumber) {
    this->routingNumber = routingNumber;
}

string BankAccount::getRoutingNumber() {
    return routingNumber;
}

void BankAccount::setAccountNumber(string accountNumber) {
    this->accountNumber = accountNumber;
}

string BankAccount::getAccountNumber() {
    return accountNumber;
}

void BankAccount::saveFile(string fileName)
{
    ofstream out(fileName);
    if(out.is_open()){
        out << balance << endl;
        out << accountNumber << endl;
        out << routingNumber << endl;
    } else {
        cout<<"Could not open file to write"<<endl;
    }
    out.close();
}

bool BankAccount::loadFile(string fileName)
{
    ifstream in(fileName);
    char str[100];
    if(in.is_open()){
        in.getline(str,100);
        balance = atof(str);
        in.getline(str,100);
        routingNumber = str;
        in.getline(str,100);
        accountNumber = str;
        return 1;
    }else{
        cout<<"Could not open file to read"<<endl;
        return 0;
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
    BankAccount aBankAccount;

//    cout<<"entering info..."<<endl;
//    aBankAccount.linkAccount();
//
//    cout<<"saving file..."<<endl<<endl;
//    aBankAccount.saveFile("bankAccount.txt");

    cout<<endl<<"loading file..."<<endl;
    aBankAccount.loadFile("bankAccount.txt");

    aBankAccount.print();
}
