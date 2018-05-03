//============================================================================
// Name        : saferoadsmain.cpp
// Author      : Aubrey Craun
// Version     :
// Copyright   : @2018 synCRAUNicity
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "contacts.h"
#include "emergencyContacts.h"
#include "driver.h"
#include "connection.h"
#include "geolocate.h"
#include "gps.h"
#include "location.h"
#include "twitter.h"
#include "contactsException.h"
#include "sensors.h"
#include "car.h"
#include "debit.h"
#include "bankaccount.h"
#include "uber.h"
#include "exceptions.h"

using namespace rapidjson;
using namespace std;

void process() {
    try {
        cout << "******************************************************************" << endl;
        cout << "*                      Welcome to SafeRoads                      *" << endl;
        cout << "*                                                                *" << endl;
        cout << "*                \"Promoting safe roads for all...\"               *" << endl;
        cout << "******************************************************************" << endl;

        Driver aDriver;
        EmergencyContacts aContacts;

        bool driverLoad = aDriver.dLoad("driver.txt");
        if(!driverLoad) {
            cout << endl << "                    *** INITIAL SETUP ***" << endl << endl;
            cout << "Step 1:" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Please answer a few questions about yourself.  If in the event " << endl;
            cout << "SafeRoads disables your car, we would need this information to " << endl;
            cout << "set up an Uber account for you or send to your trusted contacts " << endl;
            cout << "so they can offer you some assistance." << endl << endl;
            cout << "------------------------------------------------------------------" << endl;

            Driver::dProcess();
        }

        Car aCar;
        if(!aCar.load()){
            cout << "Step 2:" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Please enter information about your car.  If in the event SafeRoads " << endl;
            cout << "disables your car, we would need this information to " << endl;
            cout << "so the Uber driver or your contact can easily find you." << endl;
            cout << "------------------------------------------------------------------" << endl;
            aCar.newCar();
        }

        bool contactsLoad = aContacts.eLoad("emergencyContacts.txt");
        if(!contactsLoad) {
            cout << "Step 3:" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Now, you will now enter up to three contacts.  When you are in " << endl;
            cout << "need of assistance, these contacts will be sent a message their " << endl;
            cout << "email with your current location and your contact information so " << endl;
            cout << "they will be able offer help." << endl;
            cout << "------------------------------------------------------------------" << endl;

            EmergencyContacts::eProcess();
        }

        cout << endl << "                       *** APPLICATION ***" << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << "Now we will simulate what would happen if a person enters the car " << endl;
        cout << "and the 3 alcohol sensors find that the driver is over or under " << endl;
        cout << "the legal limit. " << endl;
        cout << "------------------------------------------------------------------" << endl;
        do
        {
          cout << '\n' << "Press a key to continue...";
        } while (cin.get() != '\n');

        Sensors aSensor;
        double avg =aSensor.calculateAverage();
        cout << endl << "Alcohol limit: "<< avg << endl;
        if(avg<LEGAL_LIMIT) {
            aCar.unlockCar();
            cout << "Lock status: " << aCar.getLockStatus() << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Driver is under the legal limit, so the car is unlocked. " << endl;
            cout << "------------------------------------------------------------------" << endl;
            do
            {
              cout << '\n' << "Press a key to continue...";
            } while (cin.get() != '\n');
        }else{
            aCar.lockCar();
            cout << "Lock status: " << aCar.getLockStatus() << endl;
            cout << "Car is locked." << endl << endl;

            Location aLocation;
            aLocation.setLocation();
            aLocation.getGeoData();
            aLocation.save("location.txt");
            aLocation.print();

            cout << "------------------------------------------------------------------" << endl;
            cout << "Driver is over the legal limit, so the car is locked and the " << endl;
            cout << "location is recorded." << endl;
            cout << "------------------------------------------------------------------" << endl;
            do
            {
              cout << '\n' << "Press a key to continue...";
            } while (cin.get() != '\n');



            int userSelection = 0;
            cout << "\nWhat would you like to do?" << endl;
            cout << "    1. Send contact a message" << endl;
            cout << "    2. Request an UBER" << endl << endl;
//
            cout << "Enter your choice: ";
            cin >> userSelection;

            Connection aConnection;
            aConnection.getLocation();

            if(userSelection == 1) {

                Contacts* aContactsArr[3];
                for(int i=0; i < 3; i++) {
                    aContactsArr[i] = aContacts.getContact(i);
                    if (!aContactsArr[i]->getEmailAddress().empty()) {
                        aConnection.sendMessgaeToContact(aDriver, aContactsArr[i]);
                    }
                }

                cout << "------------------------------------------------------------------" << endl;
                cout << "A tweet is also sent through Twitter." << endl;
                cout << "------------------------------------------------------------------" << endl;

                Twitter aTwitter;
                aTwitter.getLocation();
                aTwitter.sendTweet();
            } else if(userSelection == 2) {
                Uber::process(aDriver);
            }

            do
            {
//              cout << '\n' << "Press a key to continue...";
            } while (cin.get() != '\n');

            cout << "\n\n------------------------------------------------------------------" << endl;
            cout << "A backup battery will activate which will activate timer for 10 " << endl;
            cout << "hours.  After the timer ends another email is sent to the driver " << endl;
            cout << "making them aware of the location of the vehicle. " << endl;
            cout << "------------------------------------------------------------------" << endl;
            do
            {
              cout << '\n' << "Press a key to continue...";
            } while (cin.get() != '\n');

            cout << endl << "Activating the battery.  Counting down 10 hours before sending driver the vehicle's location" << endl << endl;
            aSensor.activateBattery();

            string firstName = aDriver.getFirstName();
            string lastName = aDriver.getLastName();
            string email = aDriver.getEmailAddress();

            aConnection.sendMessageToDriver(email, firstName, lastName);

            cout << "\n\n------------------------------------------------------------------" << endl;
            cout << "Once driver safely returns to his car, the battery will deactivate. " << endl;
            cout << "------------------------------------------------------------------" << endl;
            do
            {
              cout << '\n' << "Press a key to continue...";
            } while (cin.get() != '\n');
            aSensor.deactivateBattery();
            if(!aSensor.getBatteryStatus()) {
                cout << "Battery deactivated." << endl;
            }
        }
    }
    catch(VirtualException& e) {
        e.print1();
    }
    catch(BaseException& e) {
        e.print();
    }
}

int main(void) {
    srand(time(NULL));
//    GPS::test();
//    GeoLocate::test();
//    Location::test();
//    Connection::test();
//    Twitter::test();
//    EmergencyContacts::etest();
//    Debit::test();
//    BankAccount::test();
//    Uber::process();

    process();
    return 0;
}
