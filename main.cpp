#include "emergencyContacts.h"
#include "contacts.h"
#include "driver.h"
#include "contactsException.h"
int main()
{
    try{
        //Contacts::test();
     //EmergencyContacts::etest();
    
    
    EmergencyContacts::eProcess();
    //Driver::dtest();
    
    }
    catch(DayException& e)
    {
        e.print1();
    }
    
    catch (MonthException& e)
    {
        e.print1();
    }
    
    catch (YearException& e)
    {
        
        e.print1();
    }
    
    return 0;
}