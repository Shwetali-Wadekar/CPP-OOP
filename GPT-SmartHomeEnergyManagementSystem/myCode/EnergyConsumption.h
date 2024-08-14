/*
 * EnergyConsumption.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef ENERGYCONSUMPTION_H_
#define ENERGYCONSUMPTION_H_


#include <string>
#include "Poco/DateTime.h"

/**
 * Represents an energy consumption record for an appliance.
 */
class EnergyConsumption {
private:
    std::string applianceId; // ID of the appliance for which energy is consumed
    Poco::DateTime startTime; // Start time of the consumption
    Poco::DateTime endTime; // End time of the consumption

public:
    /**
     * Constructor for EnergyConsumption class.
     * @param applianceId ID of the appliance.
     * @param startTime Start time of the consumption.
     * @param endTime End time of the consumption.
     */
    EnergyConsumption(std::string applianceId, Poco::DateTime startTime, Poco::DateTime endTime);

    /**
     * Gets the ID of the appliance for which energy is consumed.
     * @return Appliance ID as a string.
     */
    std::string getApplianceId() const;

    /**
     * Calculates the duration of the energy consumption.
     * @return Duration of the consumption in hours.
     */
    double getDuration() const;
};
#endif /* ENERGYCONSUMPTION_H_ */
