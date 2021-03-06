#include "emergencyContacts.h"
#include <fstream>
#include <string>
using namespace std;

EmergencyContacts::EmergencyContacts()
{
    size = 0;
    for(int i = 0; i < MAX_CONTACTS_SIZE; i++) {
        pContacts[i] = 0;
    }
}

EmergencyContacts::~EmergencyContacts()
{
    for(int i = 0; i < MAX_CONTACTS_SIZE; i++) {
        if(pContacts[i])
            delete pContacts[i];
    }
}

void EmergencyContacts::addContact(string fName, string lName, string number, string email) throw(MaxException)
{
    if(size < MAX_CONTACTS_SIZE) {
        pContacts[size] = new Contacts(fName);
        pContacts[size]->setLastName(lName);
        pContacts[size]->setPhoneNumber(number);
        pContacts[size]->setEmailAddress(email);
        size++;
    } else {
        throw MaxException();
    }
}
void EmergencyContacts::eSave(string fileName)
{
    ofstream out("emergencyContacts.txt");
    if(out.is_open()) {
        out<<size<<endl;
        for(int i = 0; i < size; i++) {
            out << pContacts[i]->getFirstName() << endl;
            out << pContacts[i]->getLastName() << endl;
            out << pContacts[i]->getEmailAddress() << endl;
            out << pContacts[i]->getPhoneNumber() << endl;
        }
    } else {
        cout << "Could not open file to write" << endl;
    }
    // out<<'\0';
    out.close();
}

Contacts* EmergencyContacts::getContact(int index) {
    return pContacts[index];
}

int EmergencyContacts::getSize()
{
    return size;
}

void EmergencyContacts::setSize(int size) {
    this->size = size;
}

bool EmergencyContacts::eLoad(string fileName)
{
    ifstream in(fileName);
    char tmp[10];
    if(in.is_open()) {
        in>>size;
        in.getline(tmp,1);
        for(int i=0;i<size;i++){
            pContacts[i] = Contacts::load(&in);
        }
        return 1;
    }else{
//        cout<<"Could not open file to read"<<endl;
        return 0;
    }
    in.close();

        //        cout << "open" << endl;
//        char s1[100];
//        char s2[100];
//        char s3[100];
//        char s4[100];
//        for(int i =0; i < 3; i++) {
//            while(!in.eof()) {
//                in >> s1;
//                string tmp(s1);
//                cout << tmp << endl;
//                pContacts[i]->setFirstName(tmp);
//                Student* s = Student::load(&in);
//                if(!tmp.empty()) {
//                    cout << "not empty" << endl;
//                    Link* l = new Link(s, pl, 0);
//                    if(!pl) students = new LinkedList(l);
//                    else students->add(l);
//                    pl = l;
//                } else {
//                    cout << "empty" << endl;
//                }
//            }
//            cout << "loop";
            
//            if(size < MAX_CONTACTS_SIZE) {
//                in >> s1;
//                pContacts[i]->setFirstName(s1);
//                cout << s1 << endl;
//                cout << pContacts[i]->getFirstName() << endl;
//                pContacts[i]->getFirstName();
//                in >> s2;
//                pContacts[i]->setLastName(s2);
                //pContacts[i]->getLastName();
//                cout << "Name:" << pContacts[i]->getFirstName() << " " << pContacts[i]->getLastName() << endl;
//                cout << "Name:" << s1 << " " << s2 << endl;
                
//                in >> s3;
//                pContacts[i]->setEmailAddress(s3);
                //pContacts[i]->getEmailAddress();
                //in.getline(s3, 100);
//                cout << "Email: " << s3 << endl;
                
//                in >> s4;
//                pContacts[i]->setPhoneNumber(s4);
                //pContacts[i]->getPhoneNumber();
                //in.getline(s4, 100);
//                cout << "Phone Number: " << s4 << endl;
                
                //addContact(s1, s2, s3, s4);
//                cout << endl;
                
//            } else {
//            }
//        }
//        cout << "works";
//        return 1;
//    } else {
//        cout << "Could not open file to read" << endl;
//        return 0;
//    }
//    in.close();
}

void EmergencyContacts::eprint()
{
    for(int i = 0; i < size; i++) {
        pContacts[i]->print();
    }
}
//void EmergencyContacts::etest()
//{
//    EmergencyContacts eContacts;
//    eContacts.addContact("bob", "Jones", "eNum", "emailadres");
//    // eContacts.addContact("john", "eNum2", "emailaddress2");
//    eContacts.eprint();
//
//    eContacts.eSave("emergencyContacts.txt");
//    cout << "\nTesting Load" << endl;
//    eContacts.eLoad("emergencyContacts.txt");
//}

void EmergencyContacts::eProcess()
{

    EmergencyContacts eContacts;
    int menuChoice = 0;

    do {
        cout << "\n1. Add Emergency Contact" << endl;
        cout << "2. Save  " << endl;
        cout << "3. Load " << endl;
        cout << "4. Quit " << endl << endl;
        cout << "Enter a Choice: ";
        cin >> menuChoice;
        if(menuChoice == 1) {
            string eName1;
            cout << "\nFirst Name: ";
            cin >> eName1;
            string eName2;
            cout << "Last Name: ";
            cin >> eName2;
            string eNum;
            cout << "Phone number: ";
            cin >> eNum;
            cout << "Email Address: ";
            string eAddress;
            cin >> eAddress;
            eContacts.addContact(eName1, eName2, eNum, eAddress);
            eContacts.eprint();

        } else if(menuChoice == 2) {
            cout << "Your contacts have been saved." << endl;
            eContacts.eSave("emergencyContacts.txt");

        } else if(menuChoice == 3) {
            eContacts.eLoad("emergencyContacts.txt");
            eContacts.eprint();
            
        } else if(menuChoice == 4) {
            cout << "Goodbye!";
        }

    } while(menuChoice != 4);
}

void  EmergencyContacts::etest()
{

    EmergencyContacts aContacts;
    bool contactLoaded = aContacts.eLoad("emergencyContacts.txt");
//    cout << contactLoaded;

    Contacts* contact = aContacts.getContact(0);

    cout << contact->getLastName();

//    Contacts* arr[3];
//    for (int i = 0; i < 3; i++) {
//        arr[i] = aContacts.getContact(i);
//    }

//    cout << arr[0]->getFirstName() << endl;
//    cout << arr[1]->getFirstName() << endl;
//    cout << arr[2]->getFirstName() << endl;


//    cout << "Contacts: " << endl << endl;
//
//     for (int i = 1; i <= MAX_CONTACTS_SIZE; i++)
//    {
//    cout << "Contact " << i << " the name is: " << pContacts[i] << endl;
//    pContacts[i]->eprint();
//    }
//
//    eContacts.eprint();*/

}

