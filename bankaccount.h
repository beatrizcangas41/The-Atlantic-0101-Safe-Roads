

#ifndef  BANKACCOUNT_H
#define  BANKACCOUNT_H

#include "statistics.h"
#include "project1exceptions.h"

class BankAcc
{
    
public:
    
    BankAcc();

    void deposit(double amount);
    
    
    void withdrawal(double amount);
    
    double getBalance();
    
    
    double getTotalDeposits();
    
    
    double getTotalWithdrawals();
    
    
    double getAverageDeposit();

 
    double getAveragWithdrawal();
    
    
    double getMinDeposit();

 
    double  getMinWithdrawal();
    
    
    double getMaxDeposit();

 
    double getMaxWithdrawal();
    
    
    double getVarOfDeposits();
    
        
    double getVarOfWithdrawal();
    
    
    double getStdevOfdeposits();

 
    double  getStdevOfWithdrawal();

    void printacc(); // withdrawls, deposits
    
    void printAllStats();
    
    int getUserOptions();
    
    static void bTest();
    
    void static process();
    
    
    private:

    Stats deposits;//aggergation
    
    Stats withdrawls;//aggergation
    
    Exception ex1;
    
    double balance;
    
    
};







#endif