#Functional Specifications
This project requires developing an application for an iMX7-96 Development Board that will regulate the operation of a vehicle for potential drunk drivers.

The peripherals that are attached to this board are as follows:

1. a GPS sensor that will retreive the vehicle's location.
2. three (3) alcohol detection sensors that will detect the user's alcohol levels.

When the application starts for the first time, it will ask the user for their contact details (name, phone number, email address).  It will also ask for the birthdate of the driver.  This information will be stored permanently in the application.  The application would also ask the user to enter a minimum of one trusted contact (but no more than 3).  The application would also collect the phone number and email address of these contacts.

When the application starts for typical use, it will detect the alcohol level of the driver.  Under ideal circumstances, the sensor should read zero and application should not interfere with the vehicle’s operation.

##Typical Use Cases

Upon any detection of alcohol by the sensor, one of three cases will occur:

**Case 1:**
The application will prohibit use of the vehicle the driver stored in the system (based on their birthdate) as being under the legal drinking age at the time the detection occurs.

**Case 2:**
If detection levels are below the legal limit, the application will allow operation of the vehicle.  An Amber-like alert would be sent through Twitter warning the public of the vehicle’s general location and that they should exercise caution on the road.

**Case 3:**
If detection levels are at or above the legal limit, the application will not allow operation of the vehicle.  The location of the vehicle would then be stored and a backup battery will be activated for 24 hours of background use.  The driver would be prompted to choose one of their contacts to ask for assistance.  After the selection of a contact, the application would send a text/email message to the contact stating: the location of the vehicle, a link for the contact to call an Uber on the driver’s behalf, and the phone number of the driver.  After 24 hours, the application will check the location of the vehicle and compare with the location stored from the day before.  If the locations match, a text/email message would be send to the driver notifying them to pick up their vehicle.  Once the vehicle is successfully retrieved and the driver passes the detection tests, the battery will shut off and the location will be removed from the application’s memory.

