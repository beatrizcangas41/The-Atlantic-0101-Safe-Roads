//
//  battery.cpp
//  final
//
//  Created by Nazik Almazova on 5/1/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#include "battery.h"

Battery::Battery(){
    status = 0;
}
Battery::~Battery(){
    
}
bool Battery::testBattery(){
    /*    for future use    *
     code for testing a battery goes here */
    return 1;
}

void Battery::activate(){
    /*    for future use    *
     code for activating a battery goes here */
    status = 1;
    for(int i = 10; i>0; --i){
        cout<< i<<endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

}

void Battery::deactivate(){
    /*    for future use    *
     code for deactivating a battery goes here */
    status = 0;
}
bool Battery::getStatus(){
    return status;
}
