/*
 * connection.h
 *
 *  Created on: Apr 23, 2018
 *      Author: acraun
 */
#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <iostream>
#include <string>
#include "libraries/rapidjson/document.h"
#include "libraries/rapidjson/writer.h"
#include "libraries/rapidjson/stringbuffer.h"
#include "libraries/twitcurl/include/curl/curl.h"
#include "location.h"
#include "exceptions.h"
#include "driver.h"
#include "contacts.h"
#include "car.h"

#define SENDGRID_URL "https://api.sendgrid.com/v3/mail/send"
#define STATICMAPS_URL "https://maps.googleapis.com/maps/api/staticmap?center="

using namespace rapidjson;
using namespace std;

class Connection {
public:
    Connection();
    virtual ~Connection();
    static char* generateEmailJSONString(string email, string message);
    void sendMessgaeToContact(Driver d, Contacts* ec);
    void sendMessageToDriver(string email, string fName, string lName);
    virtual Location* getLocation();
    virtual string generateGoogleMap(bool exact);
    virtual string loadApiKey(string fileName) throw(LoadingKeyException);
    static void test();
    virtual void print();
private:
    void sendEmail(char* data);
    string staticMapsKey;
    string sendgridKey;
    Document* json;
    Location* pLocation;
    char* data;
};

#endif /* CONNECTION_H_ */
