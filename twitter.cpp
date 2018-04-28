/*
 * twitter.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: acraun
 */

#include "twitter.h"
#include "connection.h"

Twitter::Twitter() {
    consumer_key = loadKey("consumer_key.txt");
    consumer_secret = loadKey("consumer_secret.txt");
    access_token = loadKey("access_token.txt");
    access_token_secret = loadKey("access_token_secret.txt");

    twitterObj.getOAuth().setConsumerKey(consumer_key);
    twitterObj.getOAuth().setConsumerSecret(consumer_secret);
    twitterObj.getOAuth().setOAuthTokenKey(access_token);
    twitterObj.getOAuth().setOAuthTokenSecret(access_token_secret);
}

Twitter::~Twitter() {

}

string Twitter::loadKey(string fileName) {
    char key[100];
    ifstream in(fileName);
    if(in.is_open()) {
        in.getline(key,100);
    } else {
        cout << "Could not open file to read" << endl;
        return 0;
    }
    in.close();
    return key;
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

void Twitter::sendTweet(Location* location) {
    char tweetString[280];
    string tweetText;
    string response;
    tweetText = "**ADVISORY** Please exercise caution while driving in _______.";
    strcpy(tweetString, tweetText.c_str());

    response = "";
    if( twitterObj.statusUpdate(tweetString) ) {
        twitterObj.getLastWebResponse(response);
        cout << "statusUpdate web response: " << response.c_str() << endl;
    } else {
        twitterObj.getLastCurlError(response);
        cout << "statusUpdate error: " << response.c_str() << endl;
    }
}
void Twitter::print() {
    cout << consumer_key << endl;
    cout << consumer_secret << endl;
    cout << access_token << endl;
    cout << access_token_secret << endl;
}

void Twitter::test() {
    Location* pLocation = new Location(15);

    Twitter aTwitter;
//    aTwitter.print();
    aTwitter.verifyCredentials();
    aTwitter.sendTweet(pLocation);
}
