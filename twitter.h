/*
 * twitter.h
 *
 *  Created on: Apr 25, 2018
 *      Author: acraun
 */

#ifndef TWITTER_H_
#define TWITTER_H_

#include "includes/twitcurl/twitcurl.h"
#include "connection.h"

class Twitter: public Connection {
public:
    Twitter();
    virtual ~Twitter();
    void verifyCredentials();
    string generateMessage();
    void sendTweet(Location* location);
    void print();
    static void test();
private:
    string loadKey(string fileName);
    string consumer_key;
    string consumer_secret;
    string access_token;
    string access_token_secret;
    twitCurl twitterObj;
};

#endif /* TWITTER_H_ */
