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

#define SENDGRID_URL "https://api.sendgrid.com/v3/mail/send"
#define SENDGRID_KEY "Ask for key."


using namespace rapidjson;
using namespace std;

#ifndef CONNECTION_H_
#define CONNECTION_H_

class Connection {
public:
    Connection();
    virtual ~Connection();
    static char* generateEmailJSONString(string email, string message);
    void sendMessgaeToContact(string email);
    void sendMessageToDriver(string email);
    static void test();
    void print();
private:
    void sendEmail(char* data);
    Document* json;
    char* data;
};

#endif /* CONNECTION_H_ */
