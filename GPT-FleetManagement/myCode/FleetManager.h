/*
 * FleetManager.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef FLEETMANAGER_H_
#define FLEETMANAGER_H_


#include <map>
#include <vector>
#include <memory>
#include "TransportCompany.h"

/**
 * Manages multiple transportation companies and their fleets.
 */
class FleetManager {
private:
    std::map<std::string, std::unique_ptr<TransportCompany>> companies;

public:
    /**
     * Adds a new company to the manager.
     *
     * @param company the company to add
     * @returns the fleet manager for easy chaining of method invocations
     */
    FleetManager& addCompany(std::unique_ptr<TransportCompany>&& company);  // Implement to add a company to the manager

    /**
     * Returns the companies managed by the fleet manager.
     *
     * @returns the companies as a vector of pointers to the companies
     */
    std::vector<TransportCompany*> getCompanies() const;  // Implement to return all managed companies

    /**
     * Finds a company by name.
     *
     * @param name the company's name
     * @returns a pointer to the company if found, else nullptr
     */
    TransportCompany* findCompanyByName(std::string name) const;  // Implement to find a company by name
};


#endif /* FLEETMANAGER_H_ */
