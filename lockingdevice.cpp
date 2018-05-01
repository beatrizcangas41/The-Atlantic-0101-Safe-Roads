//
//  lockingdevice.cpp
//  final
//
//  Created by Nazik Almazova on 4/29/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#include "lockingdevice.h"

LockingDevice::LockingDevice(){
    status = 0;
}
LockingDevice::~LockingDevice(){
    
}
int LockingDevice::lock(){
    /*     for future use     *
     the locking code goes here */
    status = 1;
    return 1;
}

int LockingDevice::unlock(){
    /*     for future use     *
     the unlocking code goes here */
    status = 0;
    return 1;
}

bool LockingDevice::getStatus(){
    return status;
}
