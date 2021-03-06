#include "debit.h"

Debit::Debit()
{
//    debitCardNumber;
//    firstName;
//    lastName;
//    securityCode;
    month = 0;
    year = 0;
}

Debit::~Debit()
{
    for(int i = 0; i < 20; i++) {
        if(debitCardNumber[i])
            debitCardNumber[i] = 0;
    }
    debitCardNumber[0] = 0;
}

void Debit::setDebitCardNumber(string debitCardNumber)
{
    this->debitCardNumber = debitCardNumber;
}
string Debit::getDebitCardNumber()
{
    return debitCardNumber;
}
void Debit::setFirstName(string firstName)
{
    this->firstName = firstName;
}
string Debit::getFirstName()
{
    return firstName;
}
void Debit::setLastName(string lastName)
{
    this->lastName = lastName;
}
string Debit::getLastName()
{
    return lastName;
}
void Debit::setSecurityCode(string securityCode)
{
    this->securityCode = securityCode;
}
string Debit::getSecurityCode()
{
    return securityCode;
}
void Debit::setMonth(int month)
{
    this->month = month;
}
int Debit::getMonth()
{
    return month;
}
void Debit::setYear(int year)
{
    this->year = year;
}
int Debit::getYear()
{
    return year;
}

void Debit::print()
{
    cout << "Name on Credit Card: " << firstName << " " << lastName << endl;
    cout << "Debit Card Number: " << debitCardNumber << endl;
    cout << "Expiration Date: " << month << "|" << year << endl;
}

void Debit::test()
{
    Debit Card;

//    cout<<endl<<"entering info..."<<endl;
//    Card.enterCreditCard();
//
//    cout<<endl<<"saving file..."<<endl;
//    Card.saveFile("debitAccount.txt");

    cout<<endl<<"loading file..."<<endl;
    Card.loadFile("debitAccount.txt");

    Card.print();
}

void Debit::saveFile(string fileName)
{
    ofstream out(fileName);
    if(out.is_open()){
        out << firstName << endl;
        out << lastName << endl;
        out << debitCardNumber << endl;
        out << month << endl;
        out << year << endl;
    } else {
        cout<<"Could not open file to write"<<endl;
    }
    out.close();
}

bool Debit::loadFile(string fileName)
{
    ifstream in(fileName);
    char str[100];
    if(in.is_open()){
        in.getline(str,100);
        firstName = str;
        in.getline(str,100);
        lastName = str;
        in.getline(str,100);
        debitCardNumber = str;
        in.getline(str,100);
        month = atoi(str);
        in.getline(str,100);
        year = atoi(str);
        return 1;
    }else{
//        cout<<"Could not open file to read"<<endl;
        return 0;
    }
    in.close();
}

void Debit::enterCreditCard()
{
    cout << "Please enter credit card information " << endl;

    do {
        cout << "Card Number: ";
        cin >> debitCardNumber;
        if(debitCardNumber.length() > 16 || debitCardNumber.length() < 15) {
            cout << "INVALID Information! " << endl;
        }
    } while(debitCardNumber.length() > 16 || debitCardNumber.length() < 15);

    cout << endl;

    do {
        cout << "Enter name on card " << endl;
        cout << "first name: ";
        cin >> firstName;

        if(firstName.length() > 20) {
            cout << "INVALID Information! " << endl;
        }
    } while(firstName.length() > 20);

    cout << endl;

    do {
        cout << " enter name on card " << endl;
        cout << "last name: ";
        cin >> lastName;

        if(lastName.length() > 20) {
            cout << "INVALID Information! " << endl;
        }
    } while(lastName.length() > 20);

    cout << endl;

    do {
        cout << " enter security code ";
        cin >> securityCode;

        if(securityCode.length() > 4 || securityCode.length() < 3) {
            cout << "INVALID Information! " << endl;
        }
    } while(securityCode.length() > 4 || securityCode.length() < 3);

    cout << endl;

    cout << " enter expiration date " << endl;
    do {
        cout << "enter month using 2 digits: ";
        cin >> month;

        if(month < 1 || month > 12) {
            cout << "INVALID Information! " << endl;
        }

    } while(month < 1 || month > 12);

    do {
        cout << "enter year using 4 digits: ";
        cin >> year;

        if(year < 2018 || year > 9999) {
            cout << "INVALID Information! " << endl;
        }
    } while(year < 2018 || year > 9999);

    cout << "information is saved." << endl << endl;
}
