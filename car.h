//
//  car.hpp
//  final
//
//  Created by Nazik Almazova on 4/29/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#ifndef CAR_H
#define CAR_H

#include <string>
#include "lockingdevice.h"
using namespace std;

class Car{
public:
    Car();
    Car(string model, string make, string color);
    ~Car();
    int lockCar();
    int unlockCar();
    void setModel(string model);
    void setMake(string make);
    void setColor(string color);
    string getModel();
    string getMake();
    string getColor();
    bool getLockStatus();
private:
    string model;
    string make;
    string color;
    LockingDevice aLock;
};

#endif /* car_hpp */
