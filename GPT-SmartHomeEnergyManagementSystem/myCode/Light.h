/*
 * Light.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef LIGHT_H_
#define LIGHT_H_


#include "Appliance.h"

/**
 * Represents a smart light, inherits from Appliance.
 */
class Light : public Appliance {
private:
    bool isOn; // State of the light
    double powerUsage; // Power usage in watts

public:
    /**
     * Constructor for Light class.
     * @param id Unique identifier for the light.
     * @param name Name of the light.
     * @param powerUsage Power usage in watts.
     */
    Light(std::string id, std::string name, double powerUsage);

    /**
     * Toggles the light's state between on and off.
     */
    void toggle();

    /**
     * Gets the current state of the light.
     * @return True if the light is on, false otherwise.
     */
    bool isActive() const override;

    /**
     * Calculates the energy consumption of the light.
     * @return Energy consumption in kilowatt-hours (kWh).
     */
    double getEnergyConsumption(double hours) const override;

    /**
     * Displays light details.
     * @return A string containing light details.
     */
    std::string displayDetails() const override;
};


#endif /* LIGHT_H_ */
