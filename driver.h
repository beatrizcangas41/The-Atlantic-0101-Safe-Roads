#include "contacts.h"
//#include "contactsException.h"
#ifndef DRIVER_H
#define DRIVER_H

#include "contactsException.h"
class Driver:public Contacts
{
    
    
    Driver();
    
    public:
    int calculateage(int day, int month, int year) throw(DayException,MonthException,YearException);// still need to do load and save
    
    
    int getUberId();// still need to do load and save
    
    void printD();
    
    
    static void dtest();
    
private:
    int age;
    int dayB;
    int monthB;
    int yearB;
    int uberId;
  
    
};














#endif