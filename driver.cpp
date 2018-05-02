#include "driver.h"

Driver::Driver()
{
    age = 0;
    dayB = 0;
    monthB = 0;
    yearB = 0;
    uberId = "";
    pContact = 0;
}

void Driver::addContact(string fName, string lName, string number, string email)
{
        pContact = new Contacts(fName);
        pContact->setLastName(lName);
        pContact->setPhoneNumber(number);
        pContact->setEmailAddress(email);
}

int Driver::getDay()
{
    int day;
    do {
        cout << "Please enter current day:";
        cin >> day;

        if(day > 31 || day <= 0) {
            cout << "INVALID! Day needs to be between 1-31" << endl;
        }

    } while(day > 31 || day <= 0);
    return day;
}

int Driver::getMonth()
{
    int month;
    do {
        cout << "\n Please enter current month:";
        cin >> month;

        if(month > 12 || month <= 0) {
            cout << "INVALID! Month needs to be between 1-12";
        }
    } while(month > 12 || month <= 0);
    return month;
}

int Driver::getYear()
{
    int year;
    do {
        cout << "\n\n Please enter current year:";
        cin >> year;
        if(year < 2018) {
            cout << "INVALID! Year has to at at least be 2018" << endl;
        }

    } while(year < 2018);
    return year;
}

int Driver::calculateage(int day, int month, int year) throw(AgeException)
{

    day = getDay();
    month = getMonth();
    year = getYear();

    cout << "\n\n Current Date:" << month << "/" << day << "/" << year;

    do {
        cout << "\n\n Please enter YOUR year of birth:";
        cin >> yearB;
        if(yearB > year) {
            cout << "INVALID! Your year of birth cannot be greater than current year" << endl;
            // cout<<"exception....";
            throw YearException();
        }

    } while(yearB > year);

    do {
        cout << "\n\nPlease enter YOUR day of birth:";
        cin >> dayB;
        if(dayB > 31 || dayB <= 0) {

            cout << "INVALID! Day needs to be between 1-31" << endl;
        }
    } while(dayB > 31 || dayB <= 0);

    do {
        cout << "\n Please enter Your month of birth:";
        cin >> monthB;
        if(monthB > 12 || monthB <= 0) {
            cout << "INVALID! Month needs to be between 1-12";
        }
    } while(monthB > 12 || monthB <= 0);

    cout << "Date of Birth: " << monthB << "/" << dayB << "/" << yearB << endl;

    if(monthB < month) {
        if(dayB < day) {
            age = year - yearB;
        } else {
            age = year - yearB - 1;
        }

    } else {
        age = year - yearB - 1;
    }

    cout << "Age: " << age << endl;

    if(age < 21) {
        cout << "You are under 21." <<endl;
//        throw AgeException();
    }

    return age;
}

string Driver::getUberId()
{
    cout << "Please enter your Uber id:";
    cin >> uberId;

    return uberId;
}

void Driver::printD()
{
    cout << "Name:" << pContact->getFirstName() << " " << pContact->getLastName() << endl;
    cout << "Date of birth: " << monthB << "/" << dayB << "/" << yearB << endl;
    cout << "Age:" << age << endl;
    cout << "Phone Number:" << pContact->getPhoneNumber() << endl;
    cout << "Email Address:" << pContact->getEmailAddress() << endl;
    cout << "Uber ID:" << uberId;
}

void Driver::dSave(string fileName)
{
    ofstream out("driver.txt");
    if(out.is_open()) {
        // out << monthB << endl;
        // out << dayB << endl;
        // out << yearB << endl;
        out << age << endl;
        out << pContact->getFirstName() << endl;
        out << pContact->getLastName() << endl;
        // out << uberId << endl;
        out << pContact->getEmailAddress() << endl;
        out << pContact->getPhoneNumber() << endl;
    }

    else {
        cout << "File could not be found";
    }

    out.close();
}

void Driver::dLoad(string fileName)
{
    ifstream in("driver.txt");

    if(in.is_open()) {
        /*
        int dayB;
        int monthB;
        int yearB;
         */
        int age;
        char s1[100];
        char s2[200];
        char s3[100];
        char s4[100];
        /*
        in >> dayB;
        in >> monthB;
        in >> yearB;

        cout << "Date of birth: " << dayB << "/" << monthB << "/" << yearB << endl;
        */

        in >> age;
        this->age = age;
//        cout << "Age: " << age << endl;
        in >> s1;
        firstName = s1;
        in >> s2;
        lastName = s2;
//        cout << "name: " << s1 << " " << s2 << endl;
        in >> s3;
        emailAddress = s3;
//        cout << "Email Address: " << s3 << endl;
        in >> s4;
        phoneNumber = s4;
//        cout << "Phone NUmber: " << s4 << endl;
        cout << endl;
        
    }

    else {
        cout << "File could not be found";
    }

    in.close();
}

void Driver::dtest()
{
    int day1 = 0;
    int month1 = 0;
    int year1 = 0;

    Driver dDriver;

    dDriver.calculateage(day1, month1, year1);
    dDriver.addContact("Sam","Avrahami","5618345666","sdfsdf@gmail.com");
    // dDriver.getUberId();
    cout << "\n\n";
    dDriver.printD();
    cout << endl;
    cout << "Saving..." << endl;
    
    dDriver.dSave("driver.txt");
    cout << "Testing Loading Function: " << endl;
    dDriver.dLoad("driver.txt");
}

void Driver::dProcess()
{
    try {
        Driver dProcess;
        string first;
        string last;
        string phone;
        string email;

        cout << "Please enter first name: ";
        cin >> first;
        cout << "\nPlease enter last name: ";
        cin >> last;
        cout << "\nPlease enter phone number: ";
        cin >> phone;
        cout << "\nPlease enter email address: ";
        cin >> email;
        dProcess.addContact(first,last,phone,email);
        cout << endl;

        int d = 0, m = 0, y = 0;
        dProcess.calculateage(d, m, y);

        dProcess.getUberId();

        dProcess.printD();

        cout << endl;
        cout << "Load and Save: " << endl;
        dProcess.dSave("driver.txt");
        dProcess.dLoad("driver.txt");
    }
    catch(VirtualException& e) {
        e.print1();
    }
}
