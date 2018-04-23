//
//  alcohol.hpp
//  final project
//
//  Created by Nazik Almazova on 4/23/18.
//  Copyright © 2018 Nazik Almazova. All rights reserved.
//

#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

class Alcohol{
public:
    Alcohol();
    ~Alcohol();
    double calculateLevel();
private:
    double level;
};

#endif /* alcohol_hpp */
