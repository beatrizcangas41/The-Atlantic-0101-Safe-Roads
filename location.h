/*
 * Location.h
 *
 *  Created on: Apr 25, 2018
 *      Author: acraun
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <ctime>

#define NORTH_BOUNDS 26.374765
#define SOUTH_BOUNDS 26.365576
#define EAST_BOUNDS -80.097378
#define WEST_BOUNDS -80.107377

using namespace std;

class Location {
public:
    Location();
    Location(int zoom);
    Location(int zoom, double lat, double lon);
    virtual ~Location();
    double getLattitude();
    void setLattitude(double lat);
    double getLongitude();
    void setLongitude(double lon);
    int getZoom();
    void setZoom(int zoom);
    void print();
    static void test();

private:
    double getRandom(double lower, double upper);
    double lattitude;
    double longitude;
    int zoom;
};

#endif /* LOCATION_H_ */
