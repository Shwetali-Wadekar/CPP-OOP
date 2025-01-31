/*
 * SmartHome.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "SmartHome.h"
#include "User.h"
#include "Appliance.h"
#include "Light.h"
#include "ComplexAppliance.h"
#include "EnergyConsumption.h"
#include<stdexcept>
#include<memory>


//    std::string address; // Address of the smart home
//    std::map<std::string, std::shared_ptr<Appliance>> appliances; // Mapping of appliance ID to appliance
//    std::map<std::string, std::shared_ptr<User>> users; // Mapping of user ID to user
//    std::vector<std::unique_ptr<EnergyConsumption>> energyConsumptions; // List of energy consumption records
SmartHome::SmartHome(std::string address) : address(address)
{
}

std::string SmartHome::getAddress() const
{
	return address;
}

void SmartHome::addAppliance(std::shared_ptr<Appliance> appliance)
{
	auto found= appliances.find(appliance->getId());

	if( found == appliances.end()) {

		appliances.insert(std::make_pair(appliance->getId(),appliance));

	}else {
		throw std::invalid_argument("appliance ID already exists");
	}
}

void SmartHome::registerUser(std::shared_ptr<User> user)
{
	auto found= users.find(user->getId());

	if( found == users.end()) {

		users.insert(std::make_pair(user->       (),user));

	}else {
		throw std::invalid_argument("user ID already exists");
	}
}

std::shared_ptr<Appliance> SmartHome::getAppliance(
		const std::string &applianceId) const
{
	auto found= appliances.find(applianceId);

	if( found != appliances.end()) {

		return (*found).second;
	}else {
		throw std::invalid_argument("appliance ID already exists");
	}
	return nullptr;
}

void SmartHome::assignApplianceToUser(const std::string &applianceId,
		const std::string &userId)
{
	auto found= users.find(userId);
	auto foundAppliance= appliances.find(applianceId);

	std::shared_ptr<Appliance> appliance;

	if( foundAppliance != appliances.end()) {

		appliance= (*foundAppliance).second;
	}else {
		throw std::invalid_argument("appliance ID already exists");
	}

	if( found != users.end()) {

		(*found).second->addAppliance(appliance);

	}else {
		throw std::invalid_argument("user ID not exists");
	}


}

void SmartHome::recordEnergyConsumption(
		std::unique_ptr<EnergyConsumption> consumption)
{
	//	for(auto iter = appliances.begin() ; iter != appliances.end() ; ++iter) {
	//
	//		(*iter).second->getEnergyConsumption()
	//
	//	}

	this->energyConsumptions.push_back(std::move(consumption));
}

double SmartHome::totalEnergyConsumptionForUser(const std::string &userId) const
{
	std::vector<std::shared_ptr<Appliance>> userAppliances;
	double totalconsumption=0;
	auto found= users.find(userId);
	if( found != users.end()) {

		userAppliances=(*found).second->getAppliances();


		for(auto iter = energyConsumptions.begin() ; iter != energyConsumptions.end() ; ++iter) {

			for( auto it=userAppliances.begin() ; it != userAppliances.end() ; ++it) {

				if((*it)->getId()==(*iter)->getApplianceId()) {

					totalconsumption=totalconsumption+(*it)->getEnergyConsumption((*iter)->getDuration());
				}
			}
		}

	}else {

		throw std::invalid_argument("user ID not exists");
	}

	return totalconsumption;
}

std::vector<std::shared_ptr<Appliance> > SmartHome::getAppliancesForUser(
		const std::string &userId) const
{

	std::vector<std::shared_ptr<Appliance>> userAppliances;

	auto found= users.find(userId);
	if( found != users.end()) {

		userAppliances=(*found).second->getAppliances();

	}else {

		throw std::invalid_argument("user ID not exists");

	}
	return userAppliances;
}
