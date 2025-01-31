/*
 * Light.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Light.h"

Light::Light(std::string id, std::string name, double powerUsage) : Appliance(id,name) , powerUsage(powerUsage)
{
	this->isOn=0;
}

void Light::toggle()
{
	if(isOn) {
		isOn=0;
	}else {
		isOn=1;
	}
}

bool Light::isActive() const
{
	if(isOn) {
		return 1;
	}
	return 0;
}

double Light::getEnergyConsumption(double hours) const
{
	return ((powerUsage/1000)*hours);
}

std::string Light::displayDetails() const
{
	return "Id: "+id+", name:"+name+", "+"power usage: "+std::to_string(powerUsage);

}
