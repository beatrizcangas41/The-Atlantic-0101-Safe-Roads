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
#include "gps.h"

using namespace std;

class Location {
public:
    Location();
    Location(int zoom);
    virtual ~Location();
    void getLocation();
    void getLocation(double lat, double lon);
    double getLattitude();
    void setLattitude(double lat);
    double getLongitude();
    void setLongitude(double lon);
    int getZoom();
    void setZoom(int zoom);
    void load(string fileName);
    void save(string fileName);
    bool compare();
    void print();
    static void test();

private:
    double lattitude;
    double longitude;
    int zoom;
};

#endif /* LOCATION_H_ */
