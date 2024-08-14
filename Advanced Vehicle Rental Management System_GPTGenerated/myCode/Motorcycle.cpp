/*
 * Motorcycle.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "Motorcycle.h"

Motorcycle::Motorcycle(const std::string &make, const std::string &model,
		const std::string &registrationNumber, int engineCapacity) : Vehicle(make,model,registrationNumber) , engineCapacity(engineCapacity)
{
}

int Motorcycle::getEngineCapacity() const
{
	return this->engineCapacity;
}
