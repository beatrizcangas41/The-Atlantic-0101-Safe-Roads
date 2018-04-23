//
//  saferoads.cpp
//  final project
//
//  Created by Nazik Almazova on 4/23/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#include <iostream>
#include "sensors.h"
#include "alcohol.h"

using namespace std;

int main(){
    Alcohol alcoholSensor1;
    cout<<alcoholSensor1.calculateLevel()<<endl;
    return 0;
}
