/*
 * address.h
 *
 *  Created on: Apr 30, 2018
 *      Author: Aubrey Craun
 */

#ifndef GEOLOCATE_H_
#define GEOLOCATE_H_

#include <iostream>
#include <fstream>
#include <string>

#include "libraries/rapidjson/document.h"
#include "libraries/rapidjson/writer.h"
#include "libraries/rapidjson/stringbuffer.h"
#include "libraries/twitcurl/include/curl/curl.h"
#include "gps.h"
#include "exceptions.h"

#define GEOCODE_URL "https://maps.googleapis.com/maps/api/geocode/json?"

using namespace rapidjson;
using namespace std;

class GeoLocate {
public:
    GeoLocate();
    virtual ~GeoLocate();
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    void getGeoData(double lat, double lon);

    /* Getters */
    string getStreetNumber();
    string getStreet();
    string getCity();
    string getState();
    string getZip();

    /* Setters */
    void setStreetNumber(string streetNumber);
    void setStreet(string street);
    void setCity(string city);
    void setState(string state);
    void setZip(string zip);

    void print();
    static void test();
private:
    void loadApiKey() throw(LoadingKeyException);
    string geocodeApiKey;
    string streetNumber;
    string street;
    string city;
    string state;
    string zip;
};

#endif /* GEOLOCATE_H_ */
