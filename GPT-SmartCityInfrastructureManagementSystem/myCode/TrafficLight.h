/*
 * TrafficLight.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_


#include "InfrastructureElement.h"

/**
 * Represents a traffic light in the city.
 */
class TrafficLight : public InfrastructureElement {
private:
    enum class LightState { RED, YELLOW, GREEN }; // States of the traffic light
    LightState currentState; // Current state of the traffic light

public:
    /**
     * Constructor for the TrafficLight class.
     *
     * @param id Unique identifier for the traffic light.
     * @param loc Location of the traffic light.
     */
    TrafficLight(const std::string& id, const std::string& loc);

    /**
     * Perform maintenance on the traffic light.
     * This method should print out a message indicating maintenance status.
     */
    void performMaintenance() const override;

    /**
     * Get the current status of the traffic light.
     *
     * @return A string describing the current state of the traffic light.
     */
    std::string getStatus() const override;

    /**
     * Change the state of the traffic light.
     * This method should cycle through the light states (RED -> GREEN -> YELLOW -> RED).
     */
    void changeState();
};

#endif /* TRAFFICLIGHT_H_ */
