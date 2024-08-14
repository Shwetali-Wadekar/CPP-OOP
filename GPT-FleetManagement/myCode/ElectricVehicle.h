/*
 * ElectricVehicle.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef ELECTRICVEHICLE_H_
#define ELECTRICVEHICLE_H_
#include "Vehicle.h"

class ElectricVehicle : public Vehicle {
private:
    float batteryCapacity;

public:
    /**
     * Initializes a new electric vehicle with the given parameters.
     *
     * @param model the vehicle's model
     * @param mileage the mileage of the vehicle
     * @param capacity the capacity of the vehicle
     * @param batteryCapacity the battery capacity of the vehicle
     */
    ElectricVehicle(std::string model, float mileage, int capacity, float batteryCapacity);  // Constructor implementation

    /**
     * Returns the battery capacity of the electric vehicle.
     *
     * @return the battery capacity
     */
    float getBatteryCapacity() const;  // Implement to return the battery capacity
};
#endif /* ELECTRICVEHICLE_H_ */
