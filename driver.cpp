#include "contacts.h"
#include "driver.h"




 Driver::Driver()
 {
     age=0;
     dayB=0;
     monthB=0;
     yearB=0;
     uberId=0;
     
     
 }
 
 int Driver::calculateage(int day, int month, int year) throw(DayException,MonthException,YearException)
 {
     
    do
    {
    cout<<"Please enter current day:";
    cin>>day;
    if(day>31 || day<=0 )
    {
        
       throw DayException();
    }
    
    }while(day>31 || day<=0);

    do{
    cout<< "\n Please enter current month:";
    cin>> month;
    if(month>12|| month<=0)
    {
        
            throw MonthException();

    }
    }while(month>12|| month<=0);
     
     cout<<"\n\n Please enter current year:";
     cin>> year;
     cout<<"\n\n Current Date:" <<month<<"/"<<day<<"/"<<year;
     
     
     do{
      cout<<"\n\n Please enter YOUR year of birth:";
      cin>> yearB;
      if(yearB>year)
      {
          
          //cout<<"exception....";
          throw YearException();
      }
      
     }while(yearB>year);
      
      do{
     cout<<"\n\nPlease enter YOUR day of birth:";
    cin>>dayB;
    if(dayB>31 || dayB<=0)
    {
        
        throw DayException();
    }
      }while(dayB>31 || dayB<=0);
      
     
     do{
     cout<< "\n Please enter Your month of birth:";
    cin>> monthB;
    if(monthB>12|| monthB<=0)
    {
        
        throw MonthException();
    }
     }while(monthB>12|| monthB<=0);
     
     cout<<"Date of Birth: "<< monthB << "/" << dayB << "/" << yearB << endl;
    
    if (monthB < month)
    {
        if (dayB < day)
        {
            age = year - yearB; 
        }
        else 
        {
            age = year - yearB - 1;
        }
        
    }
    else 
    {
        age = year - yearB - 1;
    }
    
    cout<<"Age: " << age << endl;
     
     
     if(age<21)
     {
         
         cout<< " You are Under age!! Goodbye.";
     }
     
    return age; 
 }


int Driver::getUberId()
{
    cout<<"Please enter your Uber id:";
    cin>> uberId;
    
    return uberId;
    
    
    
}

void Driver::printD()
{
    cout<<"Date of birth: "<<monthB<<"/"<<dayB<<"/"<<yearB<<endl;
    cout<< "Age:"<<age<<endl;
    cout<<"Uber ID:"<<uberId;
    
    
}
    


void Driver::dtest()
{
    int day1=0;
    int month1=0;
    int year1=0;
    
    Driver dDriver;
    
    dDriver.calculateage(  day1,  month1,  year1);
    dDriver.getUberId();
    dDriver.printD();
    
    
}