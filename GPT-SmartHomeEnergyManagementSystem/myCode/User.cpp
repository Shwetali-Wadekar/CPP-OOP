/*
 * User.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "User.h"
#include "Appliance.h"
#include "Light.h"
#include "ComplexAppliance.h"
User::User(std::string id, std::string name) : id(id),name(name)
{
}

std::string User::getId() const
{
	return id;
}

std::string User::getName() const
{
	return name;
}

void User::addAppliance(std::shared_ptr<Appliance> appliance)
{
	appliances.push_back(appliance);
}

std::vector<std::shared_ptr<Appliance> > User::getAppliances() const
{
	return appliances;
}

std::string User::displayDetails() const
{
	std::string alldetails="";
	for(auto iter = appliances.begin() ; iter != appliances.end() ; ++iter) {
		alldetails=alldetails+(*iter)->displayDetails();

	}
	return alldetails;
}
