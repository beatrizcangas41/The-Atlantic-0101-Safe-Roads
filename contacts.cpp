
#include "contacts.h"
 

    Contacts::Contacts()
    {
        phoneNumber = "";
        name = "";
        emailAddress = "";
    }

    Contacts::Contacts(string name)
    {
        this -> name=name;
    }
    
     Contacts::~Contacts()
     {
        // COME BACK LATER
     }
     
     
    string Contacts::getName()
    {
        
        return name;
        
        
    }
    
    
    void Contacts::setName(string name)
    {
        
        this -> name=name;
        
    }
    
    string Contacts::getPhoneNumber()
    {
        return phoneNumber;
        
    }
    void Contacts::setPhoneNumber(string phoneNumber)
    {
        
        this-> phoneNumber=phoneNumber;
        
    }
    
    string Contacts::getEmailAddress()
    {
        return emailAddress;
        
    }
    void Contacts::setEmailAddress(string emailAddress)
    {
        
        this-> emailAddress=emailAddress;
        
    }
    
        /*void Contacts::save(ofstream* out)
        {
            *out <<name<<endl;
            *out<<phoneNumber<<endl;
            *out<<emailAddress<<endl;
            
        }


    Contacts* Contacts::load(ifstream* in)
    {
       Contacts* aContacts = new Contacts();
       char cont [MAX_SIZE];
        (*in).getline(cont,MAX_SIZE);
        aContacts->setName(cont);
        (*in).getline(cont,MAX_SIZE);
        aContacts->setPhoneNumber(cont);
        (*in).getline(cont,MAX_SIZE);
        aContacts->setEmailAddress(cont);
        return aContacts;
    }*/
    
    
    
    
    void Contacts::print()
    {
        cout<<"\n\n\n";
        cout <<"Name:"<< name << endl;
        cout << "phone Number:" << phoneNumber << endl;
        cout << "emailAddress:" << emailAddress << endl;
            
    }


    

    void Contacts::test()
    {
        Contacts aContacts;
        
        
        /*aContacts.setName("Samami");
        aContacts.setPhoneNumber("305 202 9732");
        aContacts.setEmailAddress("Beatriz@yahoo.com");
        cout<<"testing...." << endl << endl;
        aContacts.print();
        
        cout << "\n\n Testing the getName() function: " << endl;
        cout << "name: " << aContacts.getName() << endl << endl;
        
        //aContacts.save();
        cout << endl << endl;
        ofstream out("contacts.txt");
        if(out.is_open())
        {
            aContacts.save(&out);
            
        }
        else
        {
            cout<<"Can't open file.";
        }
            
            out.close();
        cout << "Testing the Load() function: " << endl;
        ifstream in("contacts.txt");
        aContacts.print();
        in.close();
        //Contacts c = Contacts::load();
        //c.print();
         * */
    }
    
    