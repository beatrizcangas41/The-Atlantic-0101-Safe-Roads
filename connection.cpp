/*
 * connection.cpp
 *
 *  Created on: Apr 23, 2018
 *      Author: acraun
 */

#include "connection.h"

Connection::Connection() {
    json = 0;
    data = 0;
}

Connection::~Connection() {

}

char* Connection::generateEmailJSONString(string email, string message) {
    Document d;
    d.SetObject();

    rapidjson::Document::AllocatorType& allocator = d.GetAllocator();
//    size_t sz = allocator.Size();

    Value personalizations(kArrayType);
    Value to(kArrayType);
    Value from(kArrayType);
    Value fromArr(kArrayType);
    Value content(kArrayType);

    Value personalizationsObj(kObjectType);
    Value toObj(kObjectType);
    Value fromObj(kObjectType);
    Value contentObj(kObjectType);

    Value val(kObjectType);

    string toEmail = email;
    val.SetString(toEmail.c_str(), static_cast<SizeType>(toEmail.length()), allocator);
    toObj.AddMember("email", val, allocator);
    to.PushBack(toObj, allocator);
    personalizationsObj.AddMember("to", to, allocator);
    personalizations.PushBack(personalizationsObj, allocator);
    d.AddMember("personalizations", personalizations, allocator);

    string fromEmail = "from email";
    val.SetString(fromEmail.c_str(), static_cast<SizeType>(fromEmail.length()), allocator);
    fromObj.AddMember("email", val, allocator);
    d.AddMember("from", fromObj, allocator);

    string subject = "Hello World";
    val.SetString(subject.c_str(), static_cast<SizeType>(subject.length()), allocator);
    d.AddMember("subject", val, allocator);

    string type = "text/plain";
    val.SetString(type.c_str(), static_cast<SizeType>(type.length()), allocator);
    contentObj.AddMember("type", val, allocator);
    string value = message;
    val.SetString(value.c_str(), static_cast<SizeType>(value.length()), allocator);
    contentObj.AddMember("value", val, allocator);
    content.PushBack(contentObj, allocator);
    d.AddMember("content", content, allocator);

    // Convert JSON document to string
    StringBuffer strbuf;
    Writer<StringBuffer> writer(strbuf);
    d.Accept(writer);

    string output = strbuf.GetString();
    char *str = new char[output.length() + 1];
    strcpy(str, output.c_str());
    return str;
}

void Connection::sendMessgaeToContact(string email) {
    string message = "This is a message for a contact.";
    char* data = Connection::generateEmailJSONString(email, message);
    sendEmail(data);
}

void Connection::sendMessageToDriver(string email) {
    string message = "This is a message for a driver.";
    char* data = Connection::generateEmailJSONString(email, message);
    sendEmail(data);
}

void Connection::sendEmail(char* data) {
    CURL* curl;
    CURLcode response;

    curl = curl_easy_init();
    if(curl) {
        string apiKey = "Authorization: Bearer ";
        apiKey.append(SENDGRID_KEY);
        char* api = new char[apiKey.length() + 1];
        strcpy(api, apiKey.c_str());

        struct curl_slist* chunk = NULL;
        chunk = curl_slist_append(chunk, api);
        chunk = curl_slist_append(chunk, "Content-Type: application/json");

        response = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        curl_easy_setopt(curl, CURLOPT_URL, SENDGRID_URL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(data));

        response = curl_easy_perform(curl);
        if(response != CURLE_OK) {
            cout << "curl_easy_perform() failed." << endl;
        } else {
            cout << "Email sent!" << endl;
        }
        curl_easy_cleanup(curl);
    }
}

void Connection::print() {

}

void Connection::test() {
    Connection aConnection;
    aConnection.sendMessgaeToContact("to email");
    aConnection.sendMessageToDriver("to email");
}
