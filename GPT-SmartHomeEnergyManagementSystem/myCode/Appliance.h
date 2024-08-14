/*
 * Appliance.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef APPLIANCE_H_
#define APPLIANCE_H_


#include <string>
#include <memory>

/**
 * Base class for a smart appliance.
 */
class Appliance {
protected:
    std::string id; // Unique identifier for the appliance
    std::string name; // Name of the appliance

public:
    /**
     * Constructor for Appliance class.
     * @param id Unique identifier for the appliance.
     * @param name Name of the appliance.
     */
    Appliance(std::string id, std::string name);

    /**
     * Gets the unique identifier for the appliance.
     * @return Appliance ID as a string.
     */
    std::string getId() const;

    /**
     * Gets the name of the appliance.
     * @return Appliance name as a string.
     */
    std::string getName() const;

    /**
     * Calculates the energy consumption of the appliance.
     * @return Energy consumption in kilowatt-hours (kWh).
     */
    virtual double getEnergyConsumption(double hours) const = 0;

    /**
     * Checks if the appliance is currently active.
     * @return True if active, false otherwise.
     */
    virtual bool isActive() const = 0;

    /**
     * Pure virtual method to display appliance details.
     * @return A string containing appliance details.
     */
    virtual std::string displayDetails() const = 0;
};
#endif /* APPLIANCE_H_ */
