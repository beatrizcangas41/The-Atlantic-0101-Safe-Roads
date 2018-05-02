#include "bankaccount.h"
#include "statistics.h"
#include "project1exceptions.h"

#include <math.h>


Stats::Stats()
{
    pData= new double[10];
    capacity=10;
    size=0;
    
}


Stats::Stats(int capacity)
{
   
    pData = new double[capacity];      
    this->capacity = capacity;
    size =0;


    
}



Stats::~Stats()
{
  	for(int i = 0; i < size; i++)
        {
		if(pData[i])
        {
        pData[i] = 0;
		}
	}
	
	if(pData) delete[] pData;
	pData = 0;

}



 void Stats::add(double value)
 {
     
     
     pData[size]=value;
     size++;
        
        
        
    
 }
 
 
 double Stats::get(int i)
 {
     double returnValue = pData[i];
     return returnValue;
     
     
 }
 
  void  Stats::set ( int i, double data)
  {
      pData[i] = data;
      
      
  }
  
  
  double Stats::sum()
  {
      double total = 0;
      
      for(int i=0; i< size; i++)
      {
          
          total+= pData[i];
      }
      
      return total;
      
  }
  
  
  
  double Stats::average()
  {
      double myTotal = this->sum();
      
      double avg = myTotal / size;
      return avg;
      
  }
  
  
  double Stats::min()
  {
      double minimum;
      
      minimum=pData[0];
      
      for(int i=0; i<size;i++)
      {
          
          if(pData[i]<=minimum)
          {
              
              minimum=pData[i];
          }
      }
      return minimum;
  }
  
  
  
  
  double Stats::max()
  {
     double maximum;
     
  maximum=pData[0];
  
  for(int i=0; i<size;i++)
  {
      if(pData[i]>maximum)
          {
              
              maximum=pData[i];
          }
      
  }
      return maximum;
      
  }



double Stats::var()
{
    double var = 0; //to be returned
    
    double sumSquares = 0; //used to sum the values to be used in the StDev() function
    
    double average = this->average(); // used to calculate average of the sample points
    
    double distanceFromMean; //calculate distance From the Mean
    
    for (int i =0; i < size; i++)
    {
        distanceFromMean = pData[i] - average;
        distanceFromMean = (distanceFromMean * distanceFromMean);
        sumSquares += distanceFromMean;
    }
    var = (sumSquares / this->size);
    
    return var;
}


double Stats::stdev()
{
    
    double variance = this->var();
    double stdeviation = sqrt(variance);
    return stdeviation;
}


void Stats::printStats()
{
    
    //This is to print out the elements of the Array to the user. 
    cout << "Printing values of the array: " << "< ";
    for (int i = 0; i < size; i++)
    {
        cout << pData[i] << " ";
    }
    cout << ">";
    
    //This will print out the sum of the entire array
    cout << endl << "The sum of the array: " << this->sum();
    cout << endl;
    
    //this will print out the arrays avg
    cout << "The average of the array is (" << this->sum()  << "/" << this->size << "): " << this->average() << endl;
    
    // this will print out the minimum of the array
    cout << "The minimum value in the array is: " << this->min() << endl;
    
    //this will print out the maximum value in the array;
    cout << "The maximum value in the array is: " << this->max() << endl;
    
    //this will print out the variance function which is used in the stdev function
    cout << "The variance of the array is: " << this->var() << endl;
    
    //this will print the stDev which uses the variance function
    cout << "The Standard Deviation of the array is: " << this->stdev() << endl;
    
}

void Stats::print()
{
    cout << "< ";
    for (int i = 0; i < size; i++)
    {
        cout << pData[i] << " ";
    }
    cout << ">";
}
 
 void Stats::sTest()
 {
    Stats Bank;
    
    Bank.add(2);
    cout << "Invoking add function with value: " << Bank.pData[0] << endl;
    Bank.add(5);
    cout << "Invoking add function with value: " << Bank.pData[1] << endl;
    cout << "Getting value at position i = 1: " << Bank.get(1) << endl;
    Bank.set(1,10);
    cout << "Setting value of position i=1 to 10: " << Bank.pData[1] << endl;
    Bank.printStats();
    
    Stats Bank2(0);
    for (int i = 0; i<20; i++)
    {
        Bank.add(i);
    }
    Bank2.add(5);
    cout << Bank2.average();
    
    

 
     
 }