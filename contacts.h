#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef CONTACTS_H
#define CONTACTS_H
#define MAX_SIZE 20000
class Contacts
{
  
public:

    Contacts();
    Contacts(string firstName);
    ~ Contacts();   // COME BACK LATER
    
    string getFirstName();
    string getLastName();
    void setFirstName(string firstName);
    void setLastName(string lastName);
    
    string getPhoneNumber();
    void setPhoneNumber(string phoneNumber);
    
    string getEmailAddress();
    void setEmailAddress(string emailAddress);
    void save(ofstream* out);
    static Contacts* load(ifstream* in);
   // void save();
    //static Contacts load();
    void print();
    static void test();
 
private:
     string phoneNumber;
     string firstName;
     string lastName;
     string emailAddress;
};


#endif