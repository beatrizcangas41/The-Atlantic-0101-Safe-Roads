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
//#include "saferoads.h"

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

//        bool contactsLoad = aContacts.eLoad("emergencyContacts.txt");
//        cout << contactsLoad;
//        if(!contactsLoad) {
//            EmergencyContacts::eProcess();
//        }

//                contacts.eLoad("emergencyContacts.txt");
//        Contacts* contacts = aContacts.getContact(1);
//        cout << contacts->getFirstName();
//        aContacts.eprint();

//        bool contactLoad = contacts.eLoad("emergencyContacts.txt");
//        cout << "Contact load: " << contactLoad << endl;
//
//        if(!contactLoad) {
//           EmergencyContacts::eProcess();
//        }








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
//            GPS aGPS;
//            aGPS.getCoordinates();

//            Location aLocation;
//            aLocation.load("location.txt");

//            aLocation.setLocation();
//            aLocation.setLocation(26.268,-80.1021);
//            aLocation.getGeoData();
//            aLocation.print();

//            aLocation.save("location.txt");

            Connection aConnection;
            aConnection.getLocation();
            aConnection.print();

            for(int i=0; i < 3; i++) {
                aConnection.sendMessgaeToContact("acraun@fau.edu", "Aubrey", "Craun");
            }

            Twitter aTwitter;
            aTwitter.getLocation();
            aTwitter.sendTweet();

            /* Timer goes here */
            cout << endl << endl << "Activating the battery.  Counting down 10 hours before sending driver the vehicle's location" << endl << endl;
            aSensor.activateBattery();
////
            string firstName;
            string lastName;
            string email;
            email = aDriver.getEmailAddress();
            firstName = aDriver.getFirstName();
            lastName = aDriver.getLastName();

            aConnection.sendMessageToDriver(email, firstName, lastName);
            aSensor.deactivateBattery();
            if(!aSensor.getBatteryStatus()) {
                cout << "Battery deactivated." << endl;
            }

        }

//        contacts.eprint();




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

    process();
    return 0;
}
