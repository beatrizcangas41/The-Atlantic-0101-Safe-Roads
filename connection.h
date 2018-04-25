/*
 * connection.h
 *
 *  Created on: Apr 23, 2018
 *      Author: acraun
 */
#include <iostream>
#include <string>
#include "includes/rapidjson/document.h"
#include "includes/rapidjson/writer.h"
#include "includes/rapidjson/stringbuffer.h"
#include "includes/curl/curl.h"
#include "location.h"

#define SENDGRID_URL "https://api.sendgrid.com/v3/mail/send"
#define SENDGRID_KEY "Ask for key."
#define GOOGLE_API_KEY "Ask for key."


using namespace rapidjson;
using namespace std;

#ifndef CONNECTION_H_
#define CONNECTION_H_

class Connection {
public:
    Connection();
    virtual ~Connection();
    Location* getLocation();
    static char* generateEmailJSONString(string email, string message);
    void sendMessgaeToContact(string email);
    void sendMessageToDriver(string email);
    virtual string generateGoogleMap(bool exact);
    static void test();
    void print();
private:
    void sendEmail(char* data);
    Document* json;
    Location* location;
    char* data;
};

#endif /* CONNECTION_H_ */
