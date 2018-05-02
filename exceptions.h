/*
 * exceptions.h
 *
 *  Created on: Apr 30, 2018
 *      Author: acraun
 */
#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
#include <string>

using namespace std;

class BaseException {
public:
    virtual void print() {
        cerr << errorCode << ": " << message << endl;
    }
    BaseException(){
        errorCode=100000;
        message = "SafeRoads throws and exception (Error): ";
    }
    virtual ~BaseException(){

    }
protected:
    int errorCode;
    string message;
};


class LoadingKeyException: public BaseException {
public:
    LoadingKeyException(){
        errorCode = 700000;
        message = "Key could not be loaded.";
    }
    virtual ~LoadingKeyException(){

    }
};

#endif /* EXCEPTIONS_H_ */
