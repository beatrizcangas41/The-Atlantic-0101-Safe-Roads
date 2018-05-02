//
//  battery.hpp
//  final
//
//  Created by Nazik Almazova on 5/1/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Battery{
public:
    Battery();
    ~Battery();
    bool testBattery();
    void activate();
    void deactivate();
    bool getStatus();
private:
    bool status;
};

#endif /* battery_hpp */
