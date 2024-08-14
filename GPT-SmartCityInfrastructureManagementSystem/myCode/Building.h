/*
 * Building.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef BUILDING_H_
#define BUILDING_H_



#include "InfrastructureElement.h"

/**
 * Represents a building in the city.
 */
class Building : public InfrastructureElement {
private:
    int floors;              // Number of floors in the building.
    bool isOccupied;        // Occupancy status of the building.

public:
    /**
     * Constructor for the Building class.
     *
     * @param id Unique identifier for the building.
     * @param loc Location of the building.
     * @param floorCount Number of floors in the building.
     */
    Building(const std::string& id, const std::string& loc, int floorCount);

    /**
     * Perform maintenance on the building.
     * This method should print out a message indicating maintenance status.
     */
    void performMaintenance() const override;

    /**
     * Get the current status of the building.
     *
     * @return A string describing the occupancy status and number of floors.
     */
    std::string getStatus() const override;

    /**
     * Mark the building as occupied.
     * This method should set isOccupied to true.
     */
    void occupy();

    /**
     * Mark the building as vacant.
     * This method should set isOccupied to false.
     */
    void vacate();
};
#endif /* BUILDING_H_ */
