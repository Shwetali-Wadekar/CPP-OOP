/*
 * ElectricVehicle.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(std::string model, float mileage, int capacity,
		float batteryCapacity) : Vehicle(model,mileage,capacity) , batteryCapacity(batteryCapacity)
{
}

float ElectricVehicle::getBatteryCapacity() const
{
	return batteryCapacity;
}
