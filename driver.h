#ifndef DRIVER_H
#define DRIVER_H
#include "contacts.h"

#include "contactsException.h"
class Driver:public Contacts
{
    Driver();
    
public:
    void addContact(string fName, string lName, string number, string email);
    
    int getDay();
    int getMonth();
    int getYear();
    int calculateage(int day, int month, int year) throw(AgeException);// still need to do load and save
    
    string getUberId();// still need to do load and save
    
    void dSave(string fileName);   
    static void dLoad(string fileName);  
    
    void printD();
    static void dtest();
    static void dProcess();
    
private:
    int age;
    int dayB;
    int monthB;
    int yearB;
    string uberId;
    Contacts* pContact;
  
    
};














#endif