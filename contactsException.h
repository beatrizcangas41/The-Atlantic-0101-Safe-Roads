#ifndef CONTACTSEXCEPTION_H
#define CONTACTSEXCEPTION_H
#include <iostream>
#include <string>
using namespace std;





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


    class AgeException:public VirtualException
    {
        
public:
        
        AgeException()
        {
            
            errorCode=101;
            message= "You are Under age! Error code:";
        }
        
       virtual ~AgeException()
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