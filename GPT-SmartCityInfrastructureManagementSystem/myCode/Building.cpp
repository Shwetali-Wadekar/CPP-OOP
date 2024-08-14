/*
 * Building.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Building.h"
#include <iostream>
Building::Building(const std::string &id, const std::string &loc,
		int floorCount) : InfrastructureElement(id,loc) , floors(floorCount)
{
	this->isOccupied=false;
}


std::string Building::getStatus() const
{
	if(this->isOccupied) {
		return "Building is Occupied!";
	}
	return "Building is free";
}

void Building::occupy()
{
	this->isOccupied=true;
}

void Building::performMaintenance() const
{
	std::cout<<"under maintanace"<<std::endl;

}

void Building::vacate()
{
	this->isOccupied=0;
}
