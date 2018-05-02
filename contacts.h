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
    Contacts(string name);
    ~Contacts();   // COME BACK LATER
    
    virtual string getName();
    virtual void setName(string name);
    
    virtual string getPhoneNumber();
    virtual void setPhoneNumber(string phoneNumber);
    
    virtual string getEmailAddress();
    virtual void setEmailAddress(string emailAddress);

    void save(ofstream* out);
    static Contacts* load(ifstream* in);
   // void save();
    //static Contacts load();
    void print();
    static void test();
 
private:
     string phoneNumber;
     string name;
     string emailAddress;
};


#endif
