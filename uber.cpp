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
        //        cout << "Could not open file to write" << endl;
    }
    out.close();
}

bool Uber::loadFile(string fileName)
{
    ifstream in("uberAccount.txt");
    char str[100];
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
        //        cout << "Could not open file to read" << endl;
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
    cout << "create a new password to sign in:" << endl;
    cin >> password;
    this->password = password;

    saveFile("uberAccount.txt");
}
int Uber::options()
{
    int decision;
    cout << "\nPayment Options:"<<endl;
    cout << "    1. Enter Bank Account info " << endl;
    cout << "    2. Enter debit card info " << endl;
    //  cout << " << endl;
    cout << "Enter a choice of payment: " << endl;

    cin >> decision;
    return decision;
}
void Uber::requestRide(Location* location)
{    string destination;
    location->getGeoData();
    GeoLocate* geo = location->getGeoLocate();

    cout<< "Your location is at:"<< endl << endl;
    location->print();

    cout << endl<<"Where would you like to go?" << endl;
    cin >> destination;

    cout<<"from: "<<endl;
    cout<<geo->getStreetNumber()<<" "<<geo->getStreet()<<endl;
    cout<<geo->getCity()<<" "<<geo->getState()<<" "<<geo->getZip()<<endl<<endl;
    cout<<"to: "<<endl;
    cout<<destination<<endl;
    cout << "Your Uber will be on its way!"<<endl<<endl;
    cout<< "The total amount will be 10 dollars.";
}

void Uber::print()
{
}
void Uber::process(Driver driver)
{
    int num1;
    Uber aUber;
    BankAccount aBankAccount;
    Debit aDebit;

    bool accountLoad = aUber.loadFile("uberAccount.txt");
    if(!accountLoad) {
        string email = driver.getEmailAddress();
        string fName = driver.getFirstName();
        string lName = driver.getLastName();
        string phone = driver.getPhoneNumber();
        cout << "creating Uber account..." << endl;
        aUber.createAccount(email, fName, lName, phone);
    }

    bool bankAccountLoad = aBankAccount.loadFile("bankAccount.txt");
    bool debitCardLoad = aDebit.loadFile("debitAccount.txt");

    if(!bankAccountLoad && !debitCardLoad) {
        num1 = aUber.options();
        if(num1 == 1) {
            aBankAccount.linkAccount();
            aBankAccount.saveFile("bankAccount.txt");
        } else if(num1 == 2) {
            aDebit.enterCreditCard();
            aDebit.saveFile("debitAccount.txt");
        }
    }
    Location* loc = new Location;
    loc->load("location.txt");

    aUber.requestRide(loc);
    delete loc;

    //    if(num4 == 1) {
    //        Location* location;
    //        aUber.requestRide(location);
    //    }
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
