#include "emergencyContacts.h"
#include <fstream>

 EmergencyContacts::EmergencyContacts()
 {
     size = 0;
     
     for (int i = 0; i < MAX_CONTACTS_SIZE; i++)
     {
         pContacts[i] = 0;
         
     }
 }



 EmergencyContacts::~EmergencyContacts()
 {
     for (int i = 0; i < MAX_CONTACTS_SIZE; i++)
     {
         if(pContacts[i]) 
             delete pContacts[i];
     }
     
 }

void EmergencyContacts::addContact(string name, string number, string email) //throw(MaxException)
{
    
    if(size < MAX_CONTACTS_SIZE)
    {
        pContacts[size] = new Contacts(name);
        pContacts[size] ->setPhoneNumber(number);
        pContacts[size] ->setEmailAddress(email);
        
        size++;
    }
     else 
     {
         cout<<"Invalid option";
         //exception......
         
     }
}
void EmergencyContacts::eSave(string fileName)
{

    ofstream out("emergencyContacts.txt");
    if(out.is_open()) {
        int count = 0;
    do {
        //for (int i = 0; i < 3; i++) {
            out << pContacts[count]->getName() << endl;
           // out << pContacts[count]->getEmailAddress() << endl;
            //out << pContacts[count]->getPhoneNumber() << endl;
            count++;
        } while(count < 3);
    } else {
        cout << "Could not open file to write" << endl;
    }
    out.close();
} 

void  EmergencyContacts::eprint()
{
     for(int i=0;i<size;i++)
    {
        pContacts[i]->print();
    }
    
   
    
}
void  EmergencyContacts::etest()
{
     EmergencyContacts eContacts;
     eContacts.addContact("bob","eNum","emailadres");
     eContacts.addContact("sam","eNum","emailadres");
    eContacts.eprint();
    eContacts.eSave("test.txt");
    
     /*ofstream out("emergencyContacts.txt");
        if(out.is_open())
        {
            for (int i = 0; i < MAX_CONTACTS_SIZE; i++)
            eContacts.save(&out);
            
        }
        else
        {
            cout<<"Can't open file.";
        }
            
            out.close();*/
}



void  EmergencyContacts::eProcess()
{
    EmergencyContacts eContacts;
    int menuChoice=0;
    do
    {
    cout<<"1. Add Emergency Contact"<<endl;
    cout<<"2. Quit"<<endl;
    cout<<"Enter a Choice:";
    cin>>menuChoice;
    if (menuChoice==1)
    {
        string eName;
        cout<<"Name:";
        cin>>eName;
        string eNum;
        cout<<" Phone number:";
        cin>> eNum;
        cout<<"Email Address:";
        string eAddress;
        cin>>eAddress;
        eContacts.addContact(eName,eNum,eAddress);
        eContacts.eprint();
        
            
                

        
    }
    else if( menuChoice==2)
    {
        cout<<"Goodbye!";
        
                eContacts.eSave("emergencyContacts.txt");

    }
    
    }while(menuChoice!=2);
}

/*void  EmergencyContacts::etest()
{
    
    EmergencyContacts eContacts;
    
    cout << "Contacts: " << endl << endl;
    
     for (int i = 1; i <= MAX_CONTACTS_SIZE; i++) 
    {
    cout << "Contact " << i << " the name is: " << pContacts[i] << endl;
    pContacts[i]->eprint();
    }
    
    eContacts.eprint();*/
    
    
//}