/*
 * gps.h
 *
 *  Created on: Apr 26, 2018
 *      Author: acraun
 */

#ifndef GPS_H_
#define GPS_H_

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

class GPS {
public:
    GPS();
    virtual ~GPS();
    void getLocation();
    double getRandom(double lower, double upper);
    double getLattitude();
    void setLattitude(double lattitude);
    double getLongitude();
    void setLongitude(double longitude);
    void print();
    static void test();
private:
    double lattitude;
    double longitude;
};

#endif /* GPS_H_ */
