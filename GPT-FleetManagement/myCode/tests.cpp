/*
 * tests.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */




#include "VehicleFleet.h"
#include "FleetManager.h"
#include"Vehicle.h"
#include"ElectricVehicle.h"
#include<iostream>

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}



void allTests() {
    // Create various vehicles
    // Create instances of Vehicle and ElectricVehicle with different parameters
	std::shared_ptr<Vehicle> ola(new ElectricVehicle("olas1",120,200,1000));
	std::shared_ptr<Vehicle> either(new ElectricVehicle("eitherLXI",150,250,1500));

    // Create a vehicle fleet and add vehicles to it
    // Add the created vehicles to an instance of VehicleFleet
	std::shared_ptr<VehicleFleet> fleet(new VehicleFleet());
	fleet->addVehicle(ola);
	fleet->addVehicle(either);


    // Create a transport company with the fleet
    // Initialize a TransportCompany with the created VehicleFleet
	TransportCompany company("sai ram fleet management",fleet);
	std::unique_ptr<TransportCompany> company1ptr(new TransportCompany("sai ram fleet management",fleet));

    // Verify total mileage and capacity
    // Use assert to check if the total mileage and capacity are correct
	 assertTrue(company.totalFleetMileage()==(120+150),"total milege wrong");

    // Create another company with a different fleet
    // Add different vehicles to another instance of VehicleFleet
    // Initialize another TransportCompany with this new fleet
		std::shared_ptr<Vehicle> ola2(new ElectricVehicle("tata neo",300,400,3500));
		std::shared_ptr<Vehicle> either2(new ElectricVehicle("merxedez benz",050,450,4500));

		std::shared_ptr<VehicleFleet> fleet2(new VehicleFleet());
		fleet2->addVehicle(ola2);
		fleet2->addVehicle(either2);

		TransportCompany company2("sai ram  car fleet management",fleet2);
		std::unique_ptr<TransportCompany> company2ptr(new TransportCompany("sai ram car fleet management",fleet2));


    // Create a fleet manager and add companies
    // Add both TransportCompany instances to a FleetManager
		FleetManager bhavin;
		bhavin.addCompany(move(company1ptr)).addCompany(move(company2ptr));



    // Verify companies in manager
    // Use assert to check if the companies are correctly added and retrievable by name
		assertTrue(bhavin.findCompanyByName("sai ram car fleet management")!=nullptr,"company not added to manager");
		assertTrue(bhavin.findCompanyByName("sai ram fleet management")!=nullptr,"company not added to manager");

		assertTrue(bhavin.findCompanyByName("sai ram fleet management")->getName()=="sai ram fleet management","company name wrong");
		assertTrue(bhavin.findCompanyByName("sai ram car fleet management")->getName()=="sai ram car fleet management","company name wrong");



}
