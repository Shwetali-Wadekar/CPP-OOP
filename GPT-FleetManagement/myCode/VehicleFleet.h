/*
 * VehicleFleet.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef VEHICLEFLEET_H_
#define VEHICLEFLEET_H_


#include <vector>
#include <memory>
#include "Fleet.h"
#include "Vehicle.h"
#include<list>
/**
 * Represents a concrete implementation of a fleet of vehicles.
 */
class VehicleFleet: public Fleet {
private:
    std::list<std::shared_ptr<Vehicle>> vehicles;

public:
    /**
     * Adds a vehicle to the fleet.
     *
     * @param vehicle the vehicle to add
     */
    void addVehicle(std::shared_ptr<Vehicle> vehicle);  // Implement to add a vehicle to the fleet

    /**
     * Returns the total mileage of all vehicles in the fleet.
     *
     * @return the total mileage
     */
    float totalMileage() const override;  // Implement to sum the mileage of all vehicles

    /**
     * Returns the total capacity of all vehicles in the fleet.
     *
     * @return the total capacity
     */
    int totalCapacity() const override;  // Implement to sum the capacity of all vehicles

    /**
     * Finds a vehicle by its model name.
     *
     * @param model the model name
     * @return pointer to the vehicle if found, else nullptr
     */
    Vehicle* findVehicleByModel(const std::string& model) const override;  // Implement to search for a vehicle by model name
};

#endif /* VEHICLEFLEET_H_ */
