/*
 * Vehicle.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "Vehicle.h"

Vehicle::Vehicle(std::string model, float mileage, int capacity) : model(model) , mileage(mileage) , capacity(capacity)
{
}

std::string Vehicle::getModel() const
{
	return model;
}

float Vehicle::getMileage() const
{
	return mileage;
}

int Vehicle::getCapacity() const
{
	return capacity;
}
