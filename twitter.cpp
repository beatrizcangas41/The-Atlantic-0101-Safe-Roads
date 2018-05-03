/*
 * twitter.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: Aubrey Craun
 */

#include "twitter.h"
#include "connection.h"

Twitter::Twitter() {
    pLocation = getLocation();

    consumer_key = loadApiKey("consumer_key.txt");
    consumer_secret = loadApiKey("consumer_secret.txt");
    access_token = loadApiKey("access_token.txt");
    access_token_secret = loadApiKey("access_token_secret.txt");

    twitterObj.getOAuth().setConsumerKey(consumer_key);
    twitterObj.getOAuth().setConsumerSecret(consumer_secret);
    twitterObj.getOAuth().setOAuthTokenKey(access_token);
    twitterObj.getOAuth().setOAuthTokenSecret(access_token_secret);
}

Twitter::~Twitter() {

}

string Twitter::generateMessage() {
    string tweetTxt;
    return tweetTxt;
}

void Twitter::verifyCredentials() {
    string response;
    if(twitterObj.accountVerifyCredGet()) {
        twitterObj.getLastWebResponse(response);
        cout << "accountVerifyCredGet web response: " << response.c_str() << endl;
    } else {
        twitterObj.getLastCurlError(response);
        cout << "accountVerifyCredGet error: " << response.c_str() << endl;
    }
}

void Twitter::sendTweet() {
    system_clock::time_point today;
    time_t tt;

    today = system_clock::now();
    tt = system_clock::to_time_t (today);

    char tweetString[280];
    string tweetText;
    string response;
    GeoLocate* data = pLocation->getGeoLocate();

    tweetText = "** SAFEROADS ADVISORY " + to_string(tt) + " **\nPlease exercise caution while driving in ";
    tweetText += data->getCity() + ", " + data->getState() + ".\n";
    strcpy(tweetString, tweetText.c_str());

    response = "";
    if( twitterObj.statusUpdate(tweetString) ) {
        twitterObj.getLastWebResponse(response);
//        cout << "statusUpdate web response: " << response.c_str() << endl;
        cout << "Tweet sent to @SafeRoads0101";
    } else {
        twitterObj.getLastCurlError(response);
        cout << "statusUpdate error: " << response.c_str() << endl;
    }
}
void Twitter::print() {
//    cout << consumer_key << endl;
//    cout << consumer_secret << endl;
//    cout << access_token << endl;
//    cout << access_token_secret << endl;

    pLocation->print();
}

void Twitter::test() {

//    pLocation->setLocation();
//    pLocation->getGeoData();
//    GeoLocate* loc = pLocation->getGeoLocate();
//    loc->print();
//    pLocation->print();

    Twitter aTwitter;
    aTwitter.getLocation();
//    aTwitter.print();
//    aTwitter.verifyCredentials();
    aTwitter.sendTweet();
}
