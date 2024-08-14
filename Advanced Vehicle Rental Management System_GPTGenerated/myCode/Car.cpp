/*
 * Car.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "Car.h"

Car::Car(const std::string &make, const std::string &model,
		const std::string &registrationNumber, int numberOfDoors) : Vehicle(make, model, registrationNumber) , numberOfDoors(numberOfDoors)
{
}

int Car::getNumberOfDoors() const
{
	return this->numberOfDoors;
}
