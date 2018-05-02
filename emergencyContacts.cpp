#include "emergencyContacts.h"
#include<fstream>
#include<string>
using namespace std;


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

void EmergencyContacts::addContact(string name, string number, string email) throw(MaxException)
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
         throw MaxException();
         
     }
}
void EmergencyContacts::eSave(string fileName)
{

    ofstream out("emergencyContacts.txt");
    if(out.is_open()) 
    {
        
        for (int i = 0; i < size; i++) {
            out << pContacts[i]->getName() << endl;
            out << pContacts[i]->getEmailAddress() << endl;
            out << pContacts[i]->getPhoneNumber() << endl;
        }
    } else 
    {
        cout << "Could not open file to write" << endl;
    }
    out<<'\0';
    out.close();
} 


void EmergencyContacts::eLoad(string fileName)
{
    ifstream in("emergencyContacts.txt");
    cout<<"This code was run\n";
	if (in.is_open())  
	{
		for (int i = 0 ; i < 3; i++) {
				char s[100];

            
				in.getline(s, 100);
                if(s[0]!='\0')
        {
				pContacts[i]->setName(s);
				cout << "Name: " << pContacts[i]->getName() << endl;
				
                in.getline(s, 100);
				pContacts[i]->setEmailAddress(s);
				cout << "Email: " << pContacts[i]->getEmailAddress() << endl;
				
				in.getline(s, 100);
				pContacts[i]->setPhoneNumber(s);
				cout << "Phone Number: " << pContacts[i]->getPhoneNumber() << endl;
		}
        else{
            cout << " Could not open file to write " << endl;

            break;
        }
        }
		}
	
	
	else {
			cout << " Could not open file to write " << endl;
	}
		
	in.close();
	cout << "Loading completed" << endl;
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
        eContacts.eprint();
    
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
                eContacts.eLoad("emergencyContacts.txt");
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
