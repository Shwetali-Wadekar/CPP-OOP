/*
 * Vehicle.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "Vehicle.h"

Vehicle::Vehicle(const std::string &make, const std::string &model,
		const std::string &registrationNumber, bool isAvailable) : make(make) , model(model) , registrationNumber(registrationNumber) , isAvailable(isAvailable)
{
}

std::string Vehicle::getMake() const
{
	return make;
}

std::string Vehicle::getModel() const
{
	return model;
}

std::string Vehicle::getRegistrationNumber() const
{
	return this->registrationNumber;
}

bool Vehicle::getAvailability() const
{
	return this->isAvailable;
}

void Vehicle::setAvailability(bool availability)
{
	this->isAvailable= availability;
}
