/*
 * twitter.h
 *
 *  Created on: Apr 25, 2018
 *      Author: acraun
 */

#ifndef TWITTER_H_
#define TWITTER_H_

#include <chrono>
#include "libraries/twitcurl/twitcurl.h"
#include "connection.h"

using std::chrono::system_clock;


class Twitter: public Connection {
public:
    Twitter();
    virtual ~Twitter();
    void verifyCredentials();
    string generateMessage();

    void sendTweet();
    void print();
    static void test();
private:
    string consumer_key;
    string consumer_secret;
    string access_token;
    string access_token_secret;
    twitCurl twitterObj;
    Location* pLocation;
};

#endif /* TWITTER_H_ */
