#include "debit.h"

Debit::Debit()
{
    debitCardNumber;
    firstName;
    lastName;
    securityCode;
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
    Card.enterCreditCard();
    Card.print();
    cout << endl << endl;

    Card.saveFile("DebitCard.txt");
    cout << "testing Load: " << endl;
    Card.loadFile("DebitCard.txt");
}

void Debit::saveFile(string fileName)
{
    ofstream out;
    out.open("DebitCard.txt");
    out << firstName << endl;
    out << lastName << endl;
    out << debitCardNumber << endl;
    out << month << endl;
    out << year << endl;

    out.close();
}

void Debit::loadFile(string fileName)
{
    ifstream in("DebitCard.txt");
    char line1[20];
    char line2[20];
    if(in.is_open()) {
        in >> line1;
        in >> line2;
        cout << "Name on Credit Card: " << line1 << " " << line2 << endl;
        in >> line1;
        cout << "Debit Card Number: " << debitCardNumber << endl;
        in >> line1;
        in >> line2;
        cout << "Expiration Date: " << month << "|" << year << endl;
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
