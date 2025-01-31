/*
 * VehicleRentalSystem.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "VehicleRentalSystem.h"
#include "VehicleException.h"
//  std::vector<std::unique_ptr<Vehicle>> vehicles;
//std::map<std::string, Vehicle*> rentedVehicles;
VehicleRentalSystem& VehicleRentalSystem::addVehicle(std::unique_ptr<Vehicle> vehicle)
{
	vehicles.push_back(std::move(vehicle));
	return *this;
}

Vehicle* VehicleRentalSystem::findVehicleByRegistrationNumber(
		const std::string &registrationNumber)
{
	for(auto iter= vehicles.begin() ; iter != vehicles.end() ; ++iter) {

		if( (**iter).getRegistrationNumber() == registrationNumber) {
			return (*iter).get();

		}

	}
	return nullptr;
}

void VehicleRentalSystem::rentVehicle(const std::string &registrationNumber,
		const std::string &customerID)
{
	Vehicle* found= findVehicleByRegistrationNumber(registrationNumber);

	if( found == nullptr) {
		throw VehicleException ("vehicle does not exist");
	}else {

		for(auto iter = rentedVehicles.begin() ; iter != rentedVehicles.end() ; ++iter) {
			if((*iter).second->getRegistrationNumber() == registrationNumber) {
				throw VehicleException ("vehicle is not available");
			}
		}
		found->setAvailability(false);
		rentedVehicles.insert(std::make_pair(customerID,found));

	}

}

/**
 * Returns a rented vehicle.
 *
 * @param registrationNumber the registration number of the vehicle
 * @param customerID the ID of the customer
 * @throws std::invalid_argument if the vehicle is not rented by the customer
 */
void VehicleRentalSystem::returnVehicle(const std::string &registrationNumber,
		const std::string &customerID)
{
	auto found= rentedVehicles.find(customerID);
	if(found != rentedVehicles.end() ) {

		found->second->setAvailability(true);
		rentedVehicles.erase(customerID);


	}else {
		throw VehicleException("there is no rented vehicles for this customer");
	}
}

std::vector<Vehicle*> VehicleRentalSystem::listAvailableVehicles()
{
	std::vector<Vehicle*> avaialableVehicles;
	for(auto iter = vehicles.begin() ; iter != vehicles.end() ; ++iter ){
		bool vehicleIsRented= false;
		for( auto iter2 = rentedVehicles.begin() ; iter2 != rentedVehicles.end() ; ++iter2) {

			if( (*iter2).second->getRegistrationNumber() == (**iter).getRegistrationNumber()) {
				vehicleIsRented= true;
			}
		}
		if(!vehicleIsRented) {
			avaialableVehicles.push_back((*iter).get());
		}
	}
	return avaialableVehicles;
}
