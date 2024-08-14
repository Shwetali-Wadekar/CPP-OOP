/*
 * SmartHome.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef SMARTHOME_H_
#define SMARTHOME_H_


#include <string>
#include <map>
#include <memory>
#include <vector>
#include <set>
#include <utility>
#include "Poco/DateTime.h"

/**
 * Forward declarations
 */
class Appliance;
class User;
class EnergyConsumption;

/**
 * Represents a smart home that manages appliances and users.
 */
class SmartHome {
private:
    std::string address; // Address of the smart home
    std::map<std::string, std::shared_ptr<Appliance>> appliances; // Mapping of appliance ID to appliance
    std::map<std::string, std::shared_ptr<User>> users; // Mapping of user ID to user
    std::vector<std::unique_ptr<EnergyConsumption>> energyConsumptions; // List of energy consumption records

public:
    /**
     * Constructor for SmartHome class.
     * @param address The address of the smart home.
     */
    SmartHome(std::string address);

    /**
     * Gets the address of the smart home.
     * @return Address as a string.
     */
    std::string getAddress() const;

    /**
     * Adds a new appliance to the smart home.
     * @param appliance A shared pointer to the appliance to be added.
     * @throws std::invalid_argument if appliance ID already exists.
     */
    void addAppliance(std::shared_ptr<Appliance> appliance);

    /**
     * Registers a new user in the smart home.
     * @param user A shared pointer to the user to be registered.
     * @throws std::invalid_argument if user ID already exists.
     */
    void registerUser(std::shared_ptr<User> user);

    /**
     * Retrieves an appliance by its ID.
     * @param applianceId The ID of the appliance.
     * @return A shared pointer to the appliance.
     * @throws std::out_of_range if appliance ID does not exist.
     */
    std::shared_ptr<Appliance> getAppliance(const std::string& applianceId) const;

    /**
     * Assigns an appliance to a user.
     * @param applianceId The ID of the appliance.
     * @param userId The ID of the user.
     * @throws std::out_of_range if appliance ID or user ID does not exist.
     */
    void assignApplianceToUser(const std::string& applianceId, const std::string& userId);

    /**
     * Records energy consumption for an appliance.
     * @param consumption A unique pointer to the energy consumption record.
     */
    void recordEnergyConsumption(std::unique_ptr<EnergyConsumption> consumption);

    /**
     * Calculates the total energy consumption for a user.
     * @param userId The ID of the user.
     * @return Total energy consumption in kilowatt-hours (kWh).
     * @throws std::out_of_range if user ID does not exist.
     */
    double totalEnergyConsumptionForUser(const std::string& userId) const;

    /**
     * Retrieves all appliances associated with a user.
     * @param userId The ID of the user.
     * @return A vector of shared pointers to appliances.
     * @throws std::out_of_range if user ID does not exist.
     */
    std::vector<std::shared_ptr<Appliance>> getAppliancesForUser(const std::string& userId) const;
};
#endif /* SMARTHOME_H_ */
