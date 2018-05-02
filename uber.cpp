#include "uber.h"

Uber::Uber()
{
    pBankAccount = new BankAccount;
    pDebitCard = new Debit;
    string email;
    string password;
    string firstName;
    string lastName;
    string phoneNumber;
    int choice = 0;
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
        out.close();
    } else {
        cout << "Could not open file to write" << endl;
    }
    // out<<'\0';
    out.close();
}

void Uber::loadFile(string fileName)
{
    

 ifstream in(fileName);
    if(in.is_open()) {
        
             Uber::load(&in);
        }
        return 1;
    else {
        cout << "Could not open file to read" << endl;
        return 0;
    }
    in.close();
    }
    /// example
/*bool EmergencyContacts::eLoad(string fileName)
{
    ifstream in(fileName);
    if(in.is_open()) {
        for(int i = 0; i < 3; i++) {
            pContacts[i] = Contacts::load(&in);
        }
        return 1;
    } else {
        cout << "Could not open file to read" << endl;
        return 0;
    }
    in.close();
    /// example
     * */

    void Uber::createAccount(string email, string firstName, string lastName, string phoneNumber)
    {
        this->email = email;
        this->firstName = firstName;
        this->lastName = lastName;
        this->phoneNumber = phoneNumber;
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
    /*void Uber::transaction(int choice)
    {
        switch(choice) {
        case 1: {
            pBankAccount->linkAccount();
            pBankAccount->print();
            break;
        }
        case 2: {
            pDebitCard->enterCreditCard();
        } break;
        case 3: {
            // requestRide(Location* location, int uberID);
        }
        }
    }*/
    void Uber::print()
    {
    }
    void Uber::process()
    {

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
        //loadFile("uberAcco")
        // me.account();
        // choice = me.options();
        // me.transaction(choice);
    }
