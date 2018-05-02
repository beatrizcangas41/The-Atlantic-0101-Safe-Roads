#include <iostream>
#include <string>
#include "bankaccount.h"
using namespace std;
#ifndef  STATS_H
#define STATS_H
#include "bankaccount.h"
class Stats
{
    
public:
    
    Stats();
    
    Stats(int capacity);
    
    ~Stats();
    
    
    void add(double value );
    
    
    double get(int i); 
    
    
    void  set ( int i, double data);
    
    
    double sum(); 
    
    
    double  average();
    
    
    double min();
    
    
    double  max();
    
    void print();
    
    double var();
    
    
    double stdev();
    
    
    void printStats() ; 
    
    static void sTest();

    
    
    
    private:
    
    double* pData; //array
    
    int capacity;
    
    int size;
    
    
};




#endif