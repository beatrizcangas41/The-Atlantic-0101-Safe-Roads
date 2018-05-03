/*
 * gps.h
 *
 *  Created on: Apr 26, 2018
 *      Author: Aubrey Craun
 */

#ifndef GPS_H_
#define GPS_H_

#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <ctime>


#define NORTH_BOUNDS 26.423304
#define WEST_BOUNDS -80.204537
#define SOUTH_BOUNDS 26.322953
#define EAST_BOUNDS -80.082475

using namespace std;

class GPS {
public:
    GPS();
    virtual ~GPS();
    void getCoordinates();
    double getRandom(double lower, double upper);

    /* Getters */
    double getLattitude();
    double getLongitude();

    /* Setters */
    void setLattitude(double lattitude);
    void setLongitude(double longitude);

    void print();
    static void test();
private:
    double lattitude;
    double longitude;
};

#endif /* GPS_H_ */
