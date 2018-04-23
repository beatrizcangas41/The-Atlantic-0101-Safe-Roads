//
//  alcohol.cpp
//  final project
//
//  Created by Nazik Almazova on 4/23/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#include "alcohol.h"

Alcohol::Alcohol(){
    level = 0.0;
}
Alcohol::~Alcohol(){
    
}

double Alcohol::calculateLevel(){
    static default_random_engine e;
    static uniform_real_distribution<> dis(0, 0.4);
    level = dis(e);
    return level;
}
