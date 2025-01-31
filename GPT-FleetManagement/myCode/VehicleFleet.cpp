/*
 * VehicleFleet.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "VehicleFleet.h"

void VehicleFleet::addVehicle(std::shared_ptr<Vehicle> vehicle)
{
	vehicles.push_back(vehicle);
}

float VehicleFleet::totalMileage() const
{
	float totalMilage=0;

	for(auto iter = vehicles.begin() ; iter != vehicles.end() ; ++iter) {

		totalMilage= totalMilage+ (*iter)->getMileage();


	}
	return totalMilage;
}

int VehicleFleet::totalCapacity() const
{
	int totalCapacity=0;

	for(auto iter = vehicles.begin() ; iter != vehicles.end() ; ++iter) {

		totalCapacity= totalCapacity+ (*iter)->getCapacity();


	}
	return totalCapacity;
}

Vehicle* VehicleFleet::findVehicleByModel(const std::string &model) const
{
	for(auto iter = vehicles.begin() ; iter != vehicles.end() ; ++iter) {

		if((*iter)->getModel()== model) {
			return (*iter).get();
		}
	}
	return nullptr;
}



