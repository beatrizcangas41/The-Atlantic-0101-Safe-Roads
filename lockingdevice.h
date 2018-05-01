//
//  lockingdevice.hpp
//  final
//
//  Created by Nazik Almazova on 4/29/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#ifndef LOCKINGDEVICE_H
#define LOCKINGDEVICE_H

class LockingDevice{
public:
    LockingDevice();
    ~LockingDevice();
    int lock();
    int unlock();
    bool getStatus();
private:
    bool status;
};

#endif /* lockingdevice_hpp */
