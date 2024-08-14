/*
 * InfrastructureElement.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "InfrastructureElement.h"

InfrastructureElement::InfrastructureElement(const std::string &id,
		const std::string &loc) : elementID(id) , location(loc)
{
}

InfrastructureElement::~InfrastructureElement()
{
}

std::string InfrastructureElement::getID() const
{
	return this->elementID;
}

std::string InfrastructureElement::getLocation() const
{
	return this->location;
}
