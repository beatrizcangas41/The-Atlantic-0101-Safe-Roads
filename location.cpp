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

Location::~Location() {
    zoom = 0;
    lattitude = 0;
    longitude = 0;
}

Location::Location(int zoom) {
    this->zoom = zoom;
    lattitude = 0;
    longitude = 0;
}

void Location::getLocation() {
    GPS* pGPS = new GPS();
    pGPS->getLocation();
    lattitude = pGPS->getLattitude();
    longitude = pGPS->getLongitude();
    delete pGPS;
    pGPS = 0;
}

void Location::getLocation(double lat, double lon) {
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
        out << lattitude << endl;
        out << longitude << endl;
    }else{
        cout << "Could not open file to write" << endl;
    }
    out.close();
}

bool Location::compare() {
    GPS* pCompare = new GPS();
    pCompare->getLocation();
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
    cout << "zoom: " << zoom << endl;
    cout << "lat:  " << lattitude << endl;
    cout << "long: " << longitude << endl;
    cout << this->compare() << endl;
}

void Location::test() {
    srand(time(NULL));

    Location aLocation(15);
    aLocation.load("location.txt");
    aLocation.print();
    aLocation.getLocation();
    aLocation.getLocation(26.268,-80.1021);
    aLocation.print();
    aLocation.save("location.txt");
}



