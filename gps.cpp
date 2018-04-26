/*
 * gps.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: acraun
 */

#include "gps.h"

GPS::GPS() {
    lattitude = 0;
    longitude = 0;
}

GPS::~GPS() {
    lattitude = 0;
    longitude = 0;
}

void GPS::getCoordinates() {
    this->lattitude = getRandom(SOUTH_BOUNDS, NORTH_BOUNDS);
    this->longitude = getRandom(WEST_BOUNDS, EAST_BOUNDS);
}

double GPS::getRandom(double lower, double upper) {
    double coordinate = 0;
    double random = (double)rand() / (double)RAND_MAX;
    return coordinate = lower + random * (upper - lower);
}

double GPS::getLattitude() {
    return lattitude;
}

void GPS::setLattitude(double lattitude) {
    this->lattitude = lattitude;
}

double GPS::getLongitude() {
    return longitude;
}

void GPS::setLongitude(double longitude) {
    this->longitude = longitude;
}

void GPS::print() {
//    cout << setprecision(10);
    cout << "Lat:  " << lattitude << endl;
    cout << "Long: " << longitude << endl;
}

void GPS::test() {
    srand(time(NULL));

    GPS aGPS;
    aGPS.getCoordinates();
    aGPS.print();
}

