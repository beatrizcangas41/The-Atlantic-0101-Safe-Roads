/*
 * connection.cpp
 *
 *  Created on: Apr 23, 2018
 *      Author: Aubrey Craun
 */

#include "connection.h"

Connection::Connection() {
    staticMapsKey = loadApiKey("google_staticmaps_key.txt");
    sendgridKey = loadApiKey("sendgrid_key.txt");
    json = 0;
    data = 0;
    pLocation = 0;
}

Connection::~Connection() {
    delete pLocation;
}

string Connection::loadApiKey(string fileName) throw(LoadingKeyException) {
    char tmpkey[1024];
    ifstream in(fileName);
    if(in.is_open()) {
        in.getline(tmpkey,1024);
    } else {
        throw LoadingKeyException();
    }
    in.close();
    string key(tmpkey);
    return key;
}

Location* Connection::getLocation() {
    pLocation = new Location();
    pLocation->load("location.txt");
    pLocation->getGeoData();
    return pLocation;
}

string Connection::generateGoogleMap(bool exact) {
    string urlString;
    string lat = to_string(pLocation->getLattitude());
    string lon = to_string(pLocation->getLongitude());
    int zoom = 0;

    urlString = STATICMAPS_URL;
    if (exact) {
        urlString += lat + "," + lon;
        urlString += "&markers=color:red%7Clabel:D%7C";
        urlString += lat + "," + lon;
        zoom = pLocation->getZoom() + 1;
    } else {
        GeoLocate* pGeoLocate = pLocation->getGeoLocate();
        urlString += pGeoLocate->getCity() + "," + pGeoLocate->getState();
        zoom = pLocation->getZoom() - 2;
    }
    urlString += "&zoom=" + to_string(zoom) + "&size=600x300&maptype=roadmap";
    urlString += "&key=";
    urlString += staticMapsKey;
    return urlString;
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

    string fromEmail = "acraun@cdsi.fau.edu";
    val.SetString(fromEmail.c_str(), static_cast<SizeType>(fromEmail.length()), allocator);
    fromObj.AddMember("email", val, allocator);
    d.AddMember("from", fromObj, allocator);

    string subject = "Important message from SafeRoads";
    val.SetString(subject.c_str(), static_cast<SizeType>(subject.length()), allocator);
    d.AddMember("subject", val, allocator);

    string type = "text/html";
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

//void Connection::sendMessgaeToContact(string email, string fName, string lName) {
void Connection::sendMessgaeToContact(Driver d, Contacts* ec){

    string message;
    GeoLocate* loc = pLocation->getGeoLocate();

    Car aCar;
    aCar.load();

    message =  "<p>Dear " + ec->getFirstName() + ",</p>";
    message += "<p>Your friend, "+ d.getFirstName() + " " + d.getLastName() + ", has activated SafeRoads and is in need of assistance.</p>";
    message += "<p>"+ d.getFirstName() +" is at (or near) the address of:</p>";
    message += "<p>" + loc->getStreetNumber() + " " + loc->getStreet() + "<br>";
    message += loc->getCity() + ", " + loc->getState() + " " + loc->getZip() + "</p>";

    message += "<p>Be on the lookout for a " + aCar.getColor() + " " + aCar.getMake() + " " + aCar.getModel() + ".";

    message += "<p>If you would like to contact "+ d.getFirstName() +", call " + d.getPhoneNumber() + ".</p>";

    message += "<img src=\"";
    message += generateGoogleMap(true);
    message += "\">";
    char* data = Connection::generateEmailJSONString(ec->getEmailAddress(), message);
    sendEmail(data);
}

void Connection::sendMessageToDriver(string email, string fName, string lName) {
    string message;
    GeoLocate* loc = pLocation->getGeoLocate();

    message = "<p>Dear "+fName+"</p>";
    message = "<p>We see you used our SafeRoads service in the past 10 hours.</p>";
    message += "<p>Your vehicle is at (or near) the address of:</p>";
    message += "<p>" + loc->getStreetNumber() + " " + loc->getStreet() + "<br>";
    message += loc->getCity() + ", " + loc->getState() + " " + loc->getZip() + "</p>";

    message += "<img src=\"";
    message += generateGoogleMap(true);
    message += "\">";
    char* data = Connection::generateEmailJSONString(email, message);
    sendEmail(data);
}

void Connection::sendEmail(char* data) {
    CURL* curl;
    CURLcode response;

    curl = curl_easy_init();
    if(curl) {
        string apiKey = "Authorization: Bearer ";
        apiKey.append(sendgridKey);
        char* api = new char[apiKey.length() + 1];
        strcpy(api, apiKey.c_str());

        struct curl_slist* chunk = NULL;
        chunk = curl_slist_append(chunk, api);
        chunk = curl_slist_append(chunk, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
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
    cout << "Printing keys..." << endl;
    cout << "static maps key: " << staticMapsKey << endl;
    cout << "sendgrid key: " << sendgridKey << endl;

    cout << endl << "Printing lat and long from 'Connection' class..." << endl;
    cout << setprecision(10);
    cout << pLocation->getLattitude() << endl;
    cout << pLocation->getLongitude() << endl;
    cout << endl;

    pLocation->print();

    cout << endl << "Printing specific location..." << endl;
    cout << this->generateGoogleMap(true) << endl;
    cout << endl << "Printing non-specific location..." << endl;
    cout << this->generateGoogleMap(false) << endl;
}

void Connection::test() {
    try {
        Connection aConnection;
        aConnection.getLocation();
        aConnection.print();

//        aConnection.sendMessgaeToContact();
//        aConnection.sendMessageToDriver("acraun@fau.edu", "Laura", "Craun");
    }
    catch(BaseException& e){
        e.print();
    }
}
