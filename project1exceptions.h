



#ifndef  PROJECT1EXCEPTIONS_H
#define PROJECT1EXCEPTIONS_H

#include "bankaccount.h"
#include "statistics.h"
#include "project1exceptions.h"


class Exception
{
public:
Exception();
    void print1();

    
private:
    int errorCode;
    string message;
    
};














#endif