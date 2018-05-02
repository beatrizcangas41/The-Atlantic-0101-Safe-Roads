#ifndef DRIVER_H
#define DRIVER_H
#include "contacts.h"

#include "contactsException.h"
class Driver:public Contacts
{
    
    
    
public:
    Driver();
    int getDay();
    int getMonth();
    int getYear();
    int calculateage(int day, int month, int year) throw(AgeException);// still need to do load and save
    
    string getUberId();// still need to do load and save
    


    void dSave(string fileName);   
    bool dLoad(string fileName);
    
    void printD();
    static void dtest();
    
private:
    int age;
    int dayB;
    int monthB;
    int yearB;
    string uberId;
  
    
};














#endif
