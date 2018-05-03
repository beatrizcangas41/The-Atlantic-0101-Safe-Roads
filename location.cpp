/*
 * Location.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: Aubrey Craun
 */

#include "location.h"

Location::Location() {
    pGeoLocate = 0;
    zoom = 15;
    lattitude = 0;
    longitude = 0;
}

Location::~Location() {
    zoom = 0;
    lattitude = 0;
    longitude = 0;
    delete pGeoLocate;
    pGeoLocate = 0;
}

void Location::setLocation() {
    GPS* pGPS = new GPS();
    pGPS->getCoordinates();
    lattitude = pGPS->getLattitude();
    longitude = pGPS->getLongitude();
    delete pGPS;
    pGPS = 0;
}

void Location::setLocation(double lat, double lon) {
    lattitude = lat;
    longitude = lon;
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

GeoLocate* Location::getGeoLocate() {
    return pGeoLocate;
}


void Location::getGeoData() {
    pGeoLocate = new GeoLocate;
    pGeoLocate->getGeoData(lattitude, longitude);
}

void Location::load(string fileName) {
    ifstream in(fileName);
    if(in.is_open()) {
        char str[100];
        in.getline(str,100);
        lattitude = atof(str);
        in.getline(str,100);
        longitude = atof(str);
    }else{
        cout << "Could not open file to read" << endl;
    }
    in.close();
}

void Location::save(string fileName) {
    ofstream out(fileName);
    if(out.is_open()){
        out << setprecision(10);
        out << lattitude << endl;
        out << longitude << endl;
    }else{
        cout << "Could not open file to write" << endl;
    }
    out.close();
}

bool Location::compare() {
    GPS* pCompare = new GPS();
    pCompare->getCoordinates();
    double tmpLat = pCompare->getLattitude();
    double tmpLon = pCompare->getLongitude();
    delete pCompare;
    pCompare = 0;
    if (lattitude < tmpLat - 0.03 || lattitude > tmpLat + 0.03) {
        return 0;
    }
    if (lattitude < tmpLon - 0.03 || longitude > tmpLon + 0.03) {
        return 0;
    }
    return 1;
}

void Location::print() {
//    cout << setprecision(10);
//    cout << "Printing out 'aLocation' object..." << endl;
//    cout << "zoom:   " << zoom << endl;
    cout << "lat:    " << lattitude << endl;
    cout << "long:   " << longitude << endl;

//    cout << endl;
//    cout << "Printing 'pGeoLocate' object..." << endl;
    pGeoLocate->print();
}

void Location::test() {
    srand(time(NULL));

    Location aLocation;
    aLocation.load("location.txt");

    aLocation.setLocation();
//    aLocation.setLocation(26.268,-80.1021);
    aLocation.getGeoData();
    aLocation.print();

    aLocation.save("location.txt");
}
