/*
 * Fleet.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef FLEET_H_
#define FLEET_H_


#include <memory>
#include <vector>
#include "Vehicle.h"

/**
 * Models a fleet of vehicles managed by a transportation company.
 */
class Fleet {
public:
    virtual ~Fleet();

    /**
     * Returns the total mileage of all vehicles in the fleet.
     *
     * @return the total mileage
     */
    virtual float totalMileage() const = 0;  // Implement to sum the mileage of all vehicles

    /**
     * Returns the total capacity of all vehicles in the fleet.
     *
     * @return the total capacity
     */
    virtual int totalCapacity() const = 0;  // Implement to sum the capacity of all vehicles

    /**
     * Finds a vehicle by its model name.
     *
     * @param model the model name
     * @return pointer to the vehicle if found, else nullptr
     */
    virtual Vehicle* findVehicleByModel(const std::string& model) const = 0;  // Implement to search for a vehicle by model name
};


#endif /* FLEET_H_ */
