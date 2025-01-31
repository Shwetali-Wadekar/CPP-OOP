/*
 * FleetManager.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "FleetManager.h"
#include "TransportCompany.h"

FleetManager& FleetManager::addCompany(
		std::unique_ptr<TransportCompany> &&company)
{
	this->companies.insert(std::make_pair(company->getName(),std::move(company)));
	return *this;
}

std::vector<TransportCompany*> FleetManager::getCompanies() const
{

	std::vector<TransportCompany*> allcompanies;

	for(auto iter = companies.begin() ; iter != companies.end() ; ++iter) {

		allcompanies.push_back((*iter).second.get());

	}
	return allcompanies;
}

TransportCompany* FleetManager::findCompanyByName(std::string name) const
{
	auto found= companies.find(name);

	if(found != companies.end()) {

		return found->second.get();
	}
	return nullptr;
}
