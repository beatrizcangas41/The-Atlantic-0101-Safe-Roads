#include "bankaccount.h"
#include "statistics.h"
#include "project1exceptions.h"


Exception::Exception()
{
    errorCode=203;
    message="INVALID OPTION. ERROR CODE:";
    
}

void Exception::print1()
{
    
    cout<<message<<errorCode;
}


