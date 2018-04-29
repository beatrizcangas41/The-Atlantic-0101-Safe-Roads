//============================================================================
// Name        : saferoadsmain.cpp
// Author      : Aubrey Craun
// Version     :
// Copyright   : @2018 synCRAUNicity
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "connection.h"
#include "location.h"
#include "twitter.h"
#include "gps.h"

using namespace rapidjson;
using namespace std;

int main(void) {
//    Location::test();
//    Connection::test();
    Twitter::test();
//    GPS::test();
    return 0;
}
