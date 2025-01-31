/*
 * TransportCompany.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "TransportCompany.h"
#include"Fleet.h"
TransportCompany::TransportCompany(std::string name,
		std::shared_ptr<Fleet> fleet) : name(name) ,  fleet(fleet)
{
}

std::string TransportCompany::getName() const
{
	return name;
}

float TransportCompany::totalFleetMileage() const
{
//	float totalMilageOfFleet=0;


	return fleet->totalMileage();
}

int TransportCompany::totalFleetCapacity() const
{
	return fleet->totalCapacity();
}
