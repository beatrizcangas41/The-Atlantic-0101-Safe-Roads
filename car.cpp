//
//  car.cpp
//  final
//
//  Created by Nazik Almazova on 4/29/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#include "car.h"

Car::Car(){
    aLock.unlock();
}

Car::Car(string model, string make, string color){
    this->model = model;
    this->make = make;
    this->color = color;
}

Car::~Car(){
    
}

int Car::lockCar(){
    int status = aLock.lock();
    if (status)
        return 1;
    else
        return 0;
}

int Car::unlockCar(){
    int status = aLock.unlock();
    if(status)
        return 1;
    else
        return 0;
}

void Car::setModel(string model){
    this->model = model;
}
void Car::setMake(string make){
    this->make = make;
}
void Car::setColor(string color){
    this->color = color;
}

string Car::getModel(){
    return model;
}
string Car::getMake(){
    return make;
}
string Car::getColor(){
    return color;
}

bool Car::getLockStatus(){
    if(aLock.getStatus())
        return 1;
    else
        return 0;
}
