/*
 * Vehicle.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_


#include <string>

/**
 * Represents a vehicle in the fleet.
 */
class Vehicle {
private:
    std::string model;
    float mileage;
    int capacity;

public:
    /**
     * Initializes a new vehicle with the given model, mileage, and capacity.
     *
     * @param model the vehicle's model
     * @param mileage the mileage of the vehicle
     * @param capacity the capacity of the vehicle
     */
    Vehicle(std::string model, float mileage, int capacity);  // Constructor implementation

    /**
     * Returns the vehicle's model.
     *
     * @return the model
     */
    std::string getModel() const;  // Implement to return the model

    /**
     * Returns the mileage of the vehicle.
     *
     * @return the mileage
     */
    float getMileage() const;  // Implement to return the mileage

    /**
     * Returns the capacity of the vehicle.
     *
     * @return the capacity
     */
    int getCapacity() const;  // Implement to return the capacity
};


#endif /* VEHICLE_H_ */
