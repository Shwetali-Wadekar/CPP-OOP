/*
 * Road.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Road.h"
#include<iostream>
Road::Road(const std::string &id, const std::string &loc, double len) :InfrastructureElement(id,loc) , length(len)
{
	this->isUnderRepair=false;
}


std::string Road::getStatus() const
{
	if(this->isUnderRepair) {
	return "Under repair!"; }
	return "road Available";
}

void Road::startRepair()
{
	this->isUnderRepair=true;
}

void Road::performMaintenance() const
{
	std::cout<<"under maintanace"<<std::endl;
}

void Road::finishRepair()
{
	this->isUnderRepair=false;
}
