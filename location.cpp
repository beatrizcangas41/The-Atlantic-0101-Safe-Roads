/*
 * Location.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: acraun
 */

#include "location.h"

Location::Location() {
    zoom = 0;
    lattitude = 0;
    longitude = 0;
}

Location::Location(int zoom) {
    this->zoom = zoom;
    this->lattitude = getRandom(26.3717, 26.3718);
    this->longitude = getRandom(-80.1009, -80.1012);
}

Location::Location(int zoom, double lat, double lon) {
    this->zoom = zoom;
    this->lattitude = lat;
    this->longitude = lon;
}

double Location::getRandom(double lower, double upper) {
    double coordinate;
//    sleep(1);
    srand(time(NULL));
//    return number = lower + (0.5 - ((double) rand())/RAND_MAX)*upper;


    double random = (double)rand() / RAND_MAX;
    return coordinate = lower + random * (upper - lower);
}

double Location::getLattitude() {
    return lattitude;
}

void Location::setLattitude(double lat) {
    this->lattitude = lat;
}

double Location::getLongitude() {
    return longitude;

}
void Location::setLongitude(double lon) {
    this->longitude = lon;
}

int Location::getZoom() {
    return zoom;

}
void Location::setZoom(int zoom) {
    this->zoom = zoom;
}

void Location::print() {
    cout << "zoom: " << zoom << endl;
    cout << "lat:  " << lattitude << endl;
    cout << "long: " << longitude << endl;
}

void Location::test() {
    Location aLocation(15);
    aLocation.print();
}

Location::~Location() {
    // TODO Auto-generated destructor stub
}

