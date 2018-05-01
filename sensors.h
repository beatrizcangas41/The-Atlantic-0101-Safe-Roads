//
//  sensors.h
//  final project
//
//  Created by Nazik Almazova on 4/23/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#ifndef SENSORS_H
#define SENSORS_H

#include <iostream>
#include "alcohol.h"
#include "gps.h"
#include "battery.h"
#define LEGAL_LIMIT 0.08

class Sensors{
public:
    Sensors();
    ~Sensors();
    double calculateAverage();
    double calculateVariance();
    double calculateStDev();
    void updateValues();
    void activateBattery();
    void deactivateBattery();
    bool getBatteryStatus();
    static void test();
private:
    Alcohol alcSensors[3];
    Battery aBattery;
    double recordedValues[3];
};



#endif /* sensors_hpp */
