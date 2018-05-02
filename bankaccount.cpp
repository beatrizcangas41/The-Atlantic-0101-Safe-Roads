#include "statistics.h"
#include "bankaccount.h"
#include "project1exceptions.h"
Exception ex1;


 BankAcc::BankAcc()
 
 {
     balance = 0;
 }

 int BankAcc::getUserOptions()
 {
     
     cout<<"1. Deposit\n";
     cout<<"2. Withdraw\n";
     cout<<"3. Balance\n";
     cout<<"4. Total Deposits/Witdrawals\n";
     cout<<"5. Average Deposits/Witdrawals\n";
     cout<<"6. Minimum Deposit/Witdrawals\n";
     cout<<"7. Maximum Deposit/Witdrawals\n";
     cout<<"8. Variance Deposits/Witdrawals\n";
     cout<<"9. Standard deviation Deposits/Witdrawals\n";
     cout<<"0. Quit\n\n";
      int menuChoice;
    
    cout<<"Please choose from options 1-9:";
    cin>> menuChoice;
    
    return menuChoice;
 }




void BankAcc::deposit(double amount)
{
    //Exception ex1;
    
    try{
        
        this->deposits.add(amount);
        balance += amount;
        this->getBalance(); 
        
        if (this->getBalance() > 100000)
        {
            
            throw 203;
        }
        
    }catch(int x){
        
        ex1.print1();
        cout<<endl<<"BALANCE CANNOT BE GREATER THAN $100,000.";
        
        
    }
    
    
    
    /*
    if (this->getBalance() < 100000)
    {
        this->deposits.add(amount);
        balance += amount;
        this->getBalance(); 
    }
    else
    {
        //catch(NameofCatch);
    }
   
        */
}


void BankAcc::withdrawal(double amount)
{
    
        try{
            
            this->withdrawls.add(amount);
        balance = balance - amount;
            
             if (this->getBalance() <= amount)
             {
                 throw 203;
                 
             }
            
        }catch(int x)
        {
            ex1.print1();
        cout<<endl<<"CANNOT WITHDRAW MORE MOENY THAN ACTUAL BALANCE!";
            
        }
    
    /*
    if (this->getBalance() >= amount)
    {
        this->withdrawls.add(amount);
        balance = balance - amount;
    }
    else
    {
       //catch 
    }
    */
}


double BankAcc::getBalance()
{
    return this->balance;
}

double BankAcc::getTotalDeposits()
{
    return this->deposits.sum();
}

double BankAcc::getTotalWithdrawals()
{
    return this->withdrawls.sum();
}

void BankAcc::printacc()
{
    cout << "Printing Deposit: ";
    this->deposits.print();
    cout << endl;
    
    cout << "Printing Withdrawl: ";
    this->withdrawls.print();
    cout << endl;
}

double BankAcc::getMinDeposit()
{
    return this->deposits.min();
}

double BankAcc::getMaxDeposit()
{
    return this->deposits.max();
}

double BankAcc::getMaxWithdrawal()
{
    return this->withdrawls.max();
}

double BankAcc::getMinWithdrawal()
{
    return this->withdrawls.min();   
}

double BankAcc::getAveragWithdrawal()
{
    return this->withdrawls.average();
}

double BankAcc::getAverageDeposit()
{
    return this->deposits.average();
}

double BankAcc::getVarOfDeposits()
{
    return this->deposits.var();
}

double BankAcc::getVarOfWithdrawal()
{
    return this->withdrawls.var();
}

double BankAcc::getStdevOfdeposits()
{
    return this->deposits.stdev();
}

double BankAcc::getStdevOfWithdrawal()
{
    return this->withdrawls.stdev();
}

void BankAcc::printAllStats()
{
    cout <<"Balance is: " << this->getBalance() << endl;
    cout << "Calling TotalDeposits: " << this->getTotalDeposits() << endl;
    cout << "Calling TotalWithdrawls: " << this->getTotalWithdrawals() << endl;
    cout << "Calling MaxTotalDeposits: " << this->getMaxDeposit() << endl;
    cout << "Calling MinTotalDeposits: " << this->getMinDeposit() << endl;
    cout << "Calling MaxTotalWithdrawls: " << this->getMaxWithdrawal() << endl;
    cout << "Calling MinTotalwithdrawls: " << this->getMinWithdrawal() << endl;
    cout << "Calling AverageDeposits: " << this->getAverageDeposit() << endl;
    cout << "Calling AverageWithdrawls: " << this->getAveragWithdrawal() << endl;
    cout << "Calling StdDeviationDeposits: " << this->getStdevOfdeposits() << endl;
    cout << "Calling StdDeviationWithdrawals: " << this->getStdevOfWithdrawal() << endl;
}
void  BankAcc::bTest()
{
    cout << "Testing Multiple Deposits with values: 5->10" << endl;
    BankAcc Bank;
    for (int i=5; i < 11; i++)
    {
        Bank.deposit(i);
    }
    
    cout << "Testing Multiple Deposits with values: 1->6" << endl;
    for (int i=1; i < 7; i++)
    {
        Bank.withdrawal(i);
    }
    Bank.printacc();
    
    Bank.printAllStats();
    cout << endl << endl;
    cout << endl << endl;
    
    

    
}



void  BankAcc::process()
{
    
    BankAcc acc1;
    int menuChoice=0;
  
   
   do{
       
        menuChoice= acc1.getUserOptions();
   if (menuChoice==1)
   {
       double money = 0;
       cout <<"How much?: ";
       cin >> money;
       acc1.deposit(money);
       cout << endl << endl;
   }
    
    else if(menuChoice==2)
    {
        double money = 0;
        cout <<"How much?: ";
        cin >> money;
        acc1.withdrawal(money);
        cout << endl << endl;
       
 
        
    }
    
    else if(menuChoice==3)
    {
        
        cout << "Balance: " <<  acc1.getBalance() << endl;
        cout << endl << endl;

    }
    
    else if(menuChoice==4)
    {
        cout << "TotalDeposits: " << acc1.deposits.sum() << endl;
        cout << "TotalWithdrawals: " << acc1.withdrawls.sum() << endl;
        cout << endl << endl;
        

        
    }
    
    else if (menuChoice==5)
    {
        
             cout<< "Average Deposit: " << acc1.getAverageDeposit() << endl;
             cout << "Average Withdrawal: " << acc1.getAveragWithdrawal() << endl;
             cout << endl << endl;
    }
    
    else if(menuChoice==6)
    {
        
            cout<< "Minimum Deposit: " << acc1.getMinDeposit() << endl;
            cout << "Minimum Withdrawal: " << acc1.getMinWithdrawal() << endl;
            cout << endl << endl;
 
    }
    
    else if(menuChoice==7)
    {
        
             cout<< "Maximum Deposit: " << acc1.getMaxDeposit() << endl;
             cout <<"Maximum Withdrawl: " << acc1.getMaxWithdrawal() << endl;
             cout << endl << endl;

    }
    
    else if(menuChoice==8)
    {
        
             cout<< "Variance Deposits: " << acc1.getVarOfDeposits() << endl;
             cout << "Variance Withdrawls: " << acc1.getVarOfWithdrawal() << endl;
             cout << endl << endl;
    }
    
    else if(menuChoice==9)
    {
        
             cout<< "Std Deviation Deposit: " << acc1.getStdevOfdeposits() << endl;
             cout << "Std Deviation Withdrawal: " << acc1.getStdevOfWithdrawal() << endl;
             cout << endl << endl;
             

    }
    
    else if(menuChoice==0)
    {
        
        cout<<"Goodbye.";
        cout << endl << endl;
    }
    
    else 
    {
        
        cout<<"INVALID OPTION!\n\n";
    }

   }while(menuChoice!=0);
}