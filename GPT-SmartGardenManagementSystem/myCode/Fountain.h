/*
 * Fountain.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef FOUNTAIN_H_
#define FOUNTAIN_H_



#include "GardenElement.h"

/**
 * Represents a fountain in the garden.
 */
class Fountain : public GardenElement {
private:
    bool isActive;     // Indicates if the fountain is currently active.
    int flowRate;      // Represents the flow rate of the fountain.

public:
    /**
     * Constructor that initializes the fountain with a name and sets initial states.
     * @param name The name of the fountain.
     */
    Fountain(const std::string& name);

    /**
     * Performs maintenance on the fountain, including checking its status.
     */
    void performMaintenance() const override;

    /**
     * Gets the current condition of the fountain, including its activity status and flow rate.
     * @return A string describing the current status and flow rate of the fountain.
     */
    std::string getCondition() const override;

    /**
     * Activates the fountain, setting isActive to true.
     */
    void activate();

    /**
     * Deactivates the fountain, setting isActive to false.
     */
    void deactivate();

    /**
     * Sets the flow rate of the fountain.
     * @param rate The new flow rate to be set.
     */
    void setFlowRate(int rate);
};
#endif /* FOUNTAIN_H_ */
