/*
 * ComplexAppliance.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "ComplexAppliance.h"

ComplexAppliance::ComplexAppliance(std::string id, std::string name,
		double powerUsage) : Appliance(id,name) , powerUsage(powerUsage)
{
	isOn=0;
}

double ComplexAppliance::getEnergyConsumption(double hours) const
{
	return ((powerUsage/1000)*hours);
}


bool ComplexAppliance::isActive() const
{
	if(isOn) {
		return 1;
	}
	return 0;
}

std::string ComplexAppliance::displayDetails() const
{
	return "Id: "+id+", name:"+name+", "+"power usage: "+std::to_string(powerUsage);

}
