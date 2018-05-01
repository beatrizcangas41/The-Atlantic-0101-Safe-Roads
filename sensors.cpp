//
//  sensors.cpp
//  final project
//
//  Created by Nazik Almazova on 4/23/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#include "sensors.h"

Sensors::Sensors(){
    for(int i = 0; i<3; i++){
        recordedValues[i] = alcSensors[i].calculateLevel();
    }
}

Sensors::~Sensors(){
    
}

double Sensors::calculateAverage(){
    double sum = 0.0;
    for(int i = 0; i<3; i++){
        sum+=recordedValues[i];
    }
    return sum/3;
}

double Sensors::calculateVariance(){
    double variance = 0.0;
    double mean = calculateAverage();
    for(int i=0; i<3; i++){
        variance += (recordedValues[i]-mean)*(recordedValues[i]-mean);
    }
    return variance/3;
}


double Sensors::calculateStDev(){
    return sqrt(calculateVariance());
}

void Sensors::updateValues(){
    for(int i = 0; i<3; i++){
        recordedValues[i] = alcSensors[i].calculateLevel();
    }
}

void Sensors::activateBattery(){
    aBattery.activate();
}
void Sensors::deactivateBattery(){
    aBattery.deactivate();
}

bool Sensors::getBatteryStatus(){
    if(aBattery.getStatus())
        return 1;
    else return 0;
}

void Sensors::test(){
    Sensors aSensor;
    int i = 10;
    while(i){
        cout<<"-------------------------"<<endl;
        cout<<"the average is "<<aSensor.calculateAverage()<<endl;
        cout<<"the variance is "<<aSensor.calculateVariance()<<endl;
        cout<<"standart deviation is "<<aSensor.calculateStDev()<<endl;
        cout<<"-------------------------"<<endl;
        aSensor.updateValues();
        i--;
    }
    
    
}

