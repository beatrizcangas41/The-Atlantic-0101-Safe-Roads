#include <iostream>
#include <string>
using namespace std;


#ifndef CONTACTSEXCEPTION_H
#define CONTACTSEXCEPTION_H

#include "contacts.h"
#include "driver.h"


    class VirtualException
{
public:
    
    virtual void print1()
    {
        cout<< message<< errorCode<<endl;
    }
    
    VirtualException()
    {
        errorCode=5000;
        message="Inheritance Exception. Error:";
    }

   virtual ~VirtualException()
    {
        
    }
    
protected:
    int errorCode;
    string message;
    
    
    
};


    class DayException:public VirtualException
    {
        
public:
        
        DayException()
        {
            
            errorCode=101;
            message= "Day need's to be between 1 or 31. Error code:";
        }
        
       virtual ~DayException()
        {
            
            
        }
        
        
    };
    
    
    
    
    class MonthException: public VirtualException
    {
      public:
    
        MonthException()
        {
            errorCode=202;
            message="Month need's to be between 1 and 12. Error code:";
            
        }
        
        
        virtual ~ MonthException()
        {
            
            
        }
        

    };


    class YearException:public VirtualException
    {
    public:
        YearException()
        {
        errorCode=303;
        message="Your year of birth cannot be greater then current year.Error:";
        
        }
        
    };



        class MaxException:public VirtualException
        {
    public:
            MaxException()
            {
                 errorCode=404;
            message="You cannot have more then 3 Emergency Contacts.Error:";
            
            }
                  
                    
            
            
        };




#endif