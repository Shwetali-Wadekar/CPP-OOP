/*
 * ComplexAppliance.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef COMPLEXAPPLIANCE_H_
#define COMPLEXAPPLIANCE_H_


#include "Appliance.h"

/**
 * Represents a complex appliance with additional functionality, inherits from Appliance.
 */
class ComplexAppliance : public Appliance {
private:
    double powerUsage; // Power usage in watts
    bool isOn; // State of the light


public:
    /**
     * Constructor for ComplexAppliance class.
     * @param id Unique identifier for the appliance.
     * @param name Name of the appliance.
     * @param powerUsage Power usage in watts.
     */
    ComplexAppliance(std::string id, std::string name, double powerUsage);

    /**
     * Calculates the energy consumption of the appliance.
     * @param hours Duration of usage in hours.
     * @return Energy consumption in kilowatt-hours (kWh).
     */
    double getEnergyConsumption(double hours) const;



    /**
     * Checks if the appliance is currently active.
     * @return True if active, false otherwise.
     */
    bool isActive() const override;

    /**
     * Displays appliance details.
     * @return A string containing appliance details.
     */
    std::string displayDetails() const override;
};


#endif /* COMPLEXAPPLIANCE_H_ */
