#include "contacts.h"
#define MAX_CONTACTS_SIZE 3
//#include "contactsException.h"
#ifndef EMERGENCYCONTACTS_H
#define EMERGENCYCONTACTS_H

class EmergencyContacts: public Contacts
{
public:
    EmergencyContacts();
    ~EmergencyContacts();
    
    void eContacts();
    void addContact(string name, string number, string email); //throw (MaxException);
    void deleteContact();
    static void etest();
    void eprint();
    static void eProcess();
private:
    int size;
    Contacts* pContacts[MAX_CONTACTS_SIZE];
    
    #endif
};