#ifndef EMERGENCYCONTACTS_H
#define EMERGENCYCONTACTS_H
//#include "contactsException.h"

#include <fstream>
#include "contacts.h"
#include "contactsException.h"

using namespace std;

#define MAX_CONTACTS_SIZE 3
class EmergencyContacts: public Contacts
{
public:
    EmergencyContacts();
    ~EmergencyContacts();
    
    void eContacts();
    void addContact(string fName, string lName, string number, string email) throw (MaxException);
    void deleteContact();
    void eSave(string fileName);    
    void eLoad(string fileName);   
    EmergencyContacts* eLoad(ifstream* in);
    static void etest();
    void eprint();
    static void eProcess();
private:
    int size;
    Contacts* pContacts[MAX_CONTACTS_SIZE];
    
};
    #endif