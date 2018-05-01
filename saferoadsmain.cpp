//============================================================================
// Name        : saferoadsmain.cpp
// Author      : Aubrey Craun
// Version     :
// Copyright   : @2018 synCRAUNicity
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include "connection.h"
#include "location.h"
#include "twitter.h"
#include "gps.h"
#include "sensors.h"
#include "car.h"

using namespace rapidjson;
using namespace std;

int main(void) {
//    Location::test();
//    Connection::test();
//    Twitter::test();
//    GPS::test();
    
    //search for files
    
    //if not found:
    //add a new driver and emergency contacts
    
    //if found:
    Sensors sensor1;
    Car aCar;
    if(sensor1.calculateAverage()<LEGAL_LIMIT){
        aCar.unlockCar();
    }else{
        
    }
    
    
    return 0;
}
