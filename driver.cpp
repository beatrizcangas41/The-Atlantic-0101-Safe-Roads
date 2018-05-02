#include "driver.h"

Driver::Driver()
{
    age = 0;
    dayB = 0;
    monthB = 0;
    yearB = 0;
    uberId = "";
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
            cout << "INVALID! Month needs to be betwwen 1-12";
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
        if(year<2018)
        {
            cout<<"INVALID! Year has to at at least be 2018"<<endl;
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
            cout << "INVALID! Month needs to be betwwen 1-12";
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
        cout << "You are underage.";

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
    cout << "Date of birth: " << monthB << "/" << dayB << "/" << yearB << endl;
    cout << "Age:" << age << endl;
    cout << "Uber ID:" << uberId;
}

void Driver::dSave(string fileName)
{
    ofstream out("driver.txt");
    if(out.is_open()) {
        out << monthB << endl;
        out << dayB << endl;
        out << yearB << endl;
        out << age << endl;
        out << uberId << endl;
    }

    else {
        cout << "File could not be found";
    }

    out.close();
}

bool Driver::dLoad(string fileName)
{
    ifstream in("driver.txt");

    if(in.is_open()) {
        int dayB;
        int monthB;
        int yearB;
        int age;
        char string[100];

        in >> dayB;
        in >> monthB;
        in >> yearB;
        cout << "Date of birth: " << dayB << "/" << monthB << "/" << yearB << endl;

        in >> age;
        cout << "Age: " << age << endl;

        in >> string;
        cout << "Uber ID: " << string << endl;
        cout << endl;
        return true;

    }
    else {
        cout << "File could not be found";
        return false;
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
    dDriver.getUberId();



    cout<<"\n\n";
    dDriver.printD();
    cout << "Saving..." << endl;
    dDriver.dSave("driver.txt");

    cout << "Testing Loading Function: " << endl;
    dDriver.dLoad("driver.txt");
}
