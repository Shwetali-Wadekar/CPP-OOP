/*
 * Appliance.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Appliance.h"

Appliance::Appliance(std::string id, std::string name) : id(id) , name(name)
{
}

std::string Appliance::getId() const
{
	return id;
}

std::string Appliance::getName() const
{
	return name;
}
