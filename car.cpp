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

void Car::save(){
    ofstream out("car.txt");
    if(out.is_open()){
        out << model<<endl;
        out << make<<endl;
        out << color<<endl;
    }else{
        cout<<"Could not open file to write"<<endl;
    }
    out.close();
}



Car* Car::load(){
    ifstream in("car.txt");
    Car* aCar = new Car();
    char str[50];
    in.getline(str,50);
    aCar->setModel(str);
    in.getline(str,50);
    aCar->setMake(str);
    in.getline(str,50);
    aCar->setColor(str);
    return aCar;
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
