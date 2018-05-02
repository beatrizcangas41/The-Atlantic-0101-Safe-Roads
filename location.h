/*
 * Location.h
 *
 *  Created on: Apr 25, 2018
 *      Author: acraun
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <iomanip>
#include <ctime>

#include "libraries/rapidjson/document.h"
#include "libraries/rapidjson/writer.h"
#include "libraries/rapidjson/stringbuffer.h"
#include "libraries/twitcurl/include/curl/curl.h"
#include "geolocate.h"
#include "gps.h"

using namespace rapidjson;
using namespace std;

class Location {
public:
    Location();
    virtual ~Location();
    void setLocation();
    void setLocation(double lat, double lon);
    void getGeoData();
    bool compare();
    void load(string fileName);
    void save(string fileName);

    /* Getters */
    double getLattitude();
    double getLongitude();
    int getZoom();
    GeoLocate* getGeoLocate();

    /* Setters */
    void setLattitude(double lat);
    void setLongitude(double lon);
    void setZoom(int zoom);

    void print();
    static void test();

private:
    string google_key;
    double lattitude;
    double longitude;
    int zoom;
    GeoLocate* pGeoLocate;
};

#endif /* LOCATION_H_ */
