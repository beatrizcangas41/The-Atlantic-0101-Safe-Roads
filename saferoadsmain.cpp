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

using namespace rapidjson;
using namespace std;

void process() {
    try {
        Driver aDriver;
        EmergencyContacts aContacts;

        bool driverLoad = aDriver.dLoad("driver.txt");
        if(!driverLoad) {
            Driver::dtest();
        }
        bool contactsLoad = aContacts.eLoad("emergencyContacts.txt");
        if(!contactsLoad) {
            EmergencyContacts::eProcess();
        }

        Contacts* eContacts[3];
        for (int i = 0; i < 3; i++) {
            eContacts[i] = aContacts.getContact(i);
        }

        Sensors aSensor;
        Car aCar;
        if(!aCar.load()){
            aCar.newCar();
        }

        double avg =aSensor.calculateAverage();
        cout << avg << endl;
        if(avg<LEGAL_LIMIT) {
            aCar.unlockCar();
            cout << "Lock status: " << aCar.getLockStatus() << endl;
        }else{
            aCar.lockCar();
            cout << "Lock status: " << aCar.getLockStatus() << endl;

            Location aLocation;
            aLocation.setLocation();
            aLocation.getGeoData();
            aLocation.save("location.txt");
            aLocation.print();

            int userSelection = 0;
            cout << "What would you like to do?" << endl;
            cout << "    1. Send contact a message" << endl;
            cout << "    2. Request an UBER" << endl << endl;

            cout << "Enter your choice: ";
            cin >> userSelection;

            if(userSelection == 1) {
                Connection aConnection;
                aConnection.getLocation();
                aConnection.print();

                for(int i=0; i < 3; i++) {
                    if (!eContacts[i]->getEmailAddress().empty()) {
                        aConnection.sendMessgaeToContact(aDriver, eContacts[i]);
                    }
                }

                Twitter aTwitter;
                aTwitter.getLocation();
                aTwitter.sendTweet();

                cout << endl << endl << "Activating the battery.  Counting down 10 hours before sending driver the vehicle's location" << endl << endl;
                aSensor.activateBattery();

                string firstName = aDriver.getFirstName();
                string lastName = aDriver.getLastName();
                string email = aDriver.getEmailAddress();

                aConnection.sendMessageToDriver(email, firstName, lastName);
                aSensor.deactivateBattery();
                if(!aSensor.getBatteryStatus()) {
                    cout << "Battery deactivated." << endl;
                }
            } else if(userSelection == 2) {
                Uber::process(aDriver);
            }
        }
    }
    catch(VirtualException& e) {
        e.print1();
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
