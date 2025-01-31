#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <stdexcept>
#include <Poco/DateTime.h>
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "VehicleRentalSystem.h"
#include "Customer.h"
#include "RentalRecord.h"
#include "VehicleException.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, const string& failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}
void vehicleTests(){
/**
 * Tests for the Vehicle class. (5 points)
 * - Create a Vehicle instance.
 * - Assert the getters return the expected values.
 * - Change the availability and assert the new value.
 */

	Vehicle truck("tata","chhota hathi","MA-SG",true);
	assertTrue(truck.getModel()== "chhota hathi","getter is not sexy");
	assertTrue(truck.getAvailability()==true,"truck is not avaialble");
	truck.setAvailability(false);
	assertTrue(truck.getAvailability()==false,"truck is avaialble");

}

void carTests(){
/**
 * Tests for the Car class. (5 points)
 * - Create a Car instance.
 * - Assert the getters return the expected values.
 * - Assert the number of doors.
 */
	Car wagonr("suzuki","lxi","GJ05-CS-8322",4);


	assertTrue(wagonr.getModel()== "lxi","getter is not sexy");
	assertTrue(wagonr.getNumberOfDoors()==4,"door are not expected");

}

void motorcycleTests(){
/**
 * Tests for the Motorcycle class. (5 points)
 * - Create a Motorcycle instance.
 * - Assert the getters return the expected values.
 * - Assert the engine capacity.
 */
	Motorcycle aviator("suzuki","v","GJ05-HN-9168",124);
	assertTrue(aviator.getModel()== "v","getter is not sexy");
	assertTrue(aviator.getEngineCapacity()==124,"engine capacity is incorrect");
}

void customerTests(){
/**
 * Tests for the Customer class. (5 points)
 * - Create a Customer instance.
 * - Assert the getters return the expected values.
 */
	Customer bhavin("Bhavin","C1");
	assertTrue(bhavin.getName()=="Bhavin","name is matched");


}
//std::vector<std::unique_ptr<Vehicle>> vehicles;
//std::map<std::string, Vehicle*> rentedVehicles;

void rentalsystemTests(){
/**
 * Tests for the VehicleRentalSystem class. (10 points)
 * - Add vehicles to the system.
 * - Rent a vehicle and assert the availability changes.
 * - Return a vehicle and assert the availability changes.
 * - List available vehicles and assert the list is correct.
 */
	std::unique_ptr<Vehicle> wagonr(new Car("suzuki","lxi","GJ05-CS-8322",4));
	std::unique_ptr<Vehicle> avaitor(new  Motorcycle("suzuki","v","GJ05-HN-9168",124));
	std::unique_ptr<Vehicle> benz(new Car("mercedes","benz","GJ05-CS-8323",10));
	std::unique_ptr<Vehicle> bmw(new Car("bmw","i3","GJ05-CS-8324",15));
	std::unique_ptr<Vehicle> opel(new Car("opel","i1","GJ05-CS-8325",1));
	std::unique_ptr<Vehicle> v(new Vehicle("opel","i1","GJ05-CS-8328",1));

	VehicleRentalSystem rentalSystem;
	rentalSystem.addVehicle(std::move(wagonr)).addVehicle(move(avaitor)).addVehicle(move(benz)).addVehicle(move(bmw)).addVehicle(move(opel)).addVehicle(move(v));
	Customer bhavin("Bhavin","C1");
	rentalSystem.rentVehicle("GJ05-CS-8322",bhavin.getCustomerID());

	try {
		rentalSystem.rentVehicle("GJ05-CS-8322","no");

	}catch ( std::exception& e) {
		cout<<e.what()<<endl;
	}


	assertTrue(rentalSystem.findVehicleByRegistrationNumber("GJ05-CS-8322")->getAvailability()==0,"vehicle is not rented");
	cout<<rentalSystem.findVehicleByRegistrationNumber("GJ05-CS-8328")->getMake()<<endl;

	auto availableVehicles =rentalSystem.listAvailableVehicles();

	assertTrue(availableVehicles.size()==5,"list of available vehicles are not correct");

	rentalSystem.returnVehicle("GJ05-CS-8322",bhavin.getCustomerID());

	auto availableVehicles2 =rentalSystem.listAvailableVehicles();
	assertTrue(availableVehicles2.size()==6,"list of available vehicles are not correct");

	try {
		rentalSystem.returnVehicle("GJ05-CS2",bhavin.getCustomerID());

	}catch ( std::exception& e) {
		cout<<e.what()<<endl;
	}





//	for(auto i: availableVehicles) {
//		cout<<i->getRegistrationNumber()<<" "<<i->getModel()<<endl;
//	}
}

void RentalRecordTests(){
/**
 * Tests for the RentalRecord class. (10 points)
 * - Create a RentalRecord instance.
 * - Assert the getters return the expected values.
 * - Calculate the rental duration and assert the correct value.
 */
	Car* wagonr2= new Car("suzuki","lxi","GJ05-CS-8322",4);
	Customer* bhavin2= new Customer("Bhavin","C1");
	RentalRecord record(wagonr2,bhavin2,Poco::DateTime(2024,02,01,12,10,00),Poco::DateTime(2024,03,01,13,10,0));

	cout<<record.calculateRentalDuration();

}

void exceptionHandleTests(){
/**
 * Tests for exception handling. (5 points)
 * - Attempt to rent a non-existent vehicle and catch the exception.
 * - Attempt to return a vehicle not rented by the customer and catch the exception.
 */
}

void allTests(){

	vehicleTests();
	carTests();
	motorcycleTests();
	customerTests();
	rentalsystemTests();
	RentalRecordTests();
	exceptionHandleTests();
}
