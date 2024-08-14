/*
 * Road.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef ROAD_H_
#define ROAD_H_


#include "InfrastructureElement.h"

/**
 * Represents a road in the city.
 */
class Road : public InfrastructureElement {
private:
    double length;        // Length of the road in kilometers.
    bool isUnderRepair;  // Repair status of the road.

public:
    /**
     * Constructor for the Road class.
     *
     * @param id Unique identifier for the road.
     * @param loc Location of the road.
     * @param len Length of the road.
     */
    Road(const std::string& id, const std::string& loc, double len);

//    /**
//     * Perform maintenance on the road.
//     * This method should print out a message indicating maintenance status.
//     */
    void performMaintenance() const override;

    /**
     * Get the current status of the road.
     *
     * @return A string describing whether the road is under repair or not.
     */
    std::string getStatus() const override;

    /**
     * Start repairing the road.
     * This method should set isUnderRepair to true.
     */
    void startRepair();

    /**
     * Finish repairing the road.
     * This method should set isUnderRepair to false.
     */
    void finishRepair();
};


#endif /* ROAD_H_ */
