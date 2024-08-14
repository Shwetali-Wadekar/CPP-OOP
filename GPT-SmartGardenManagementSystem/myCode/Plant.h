/*
 * Plant.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef PLANT_H_
#define PLANT_H_


#include "GardenElement.h"

/**
 * Represents a plant in the garden.
 */
class Plant : public GardenElement {
private:
    bool isWatered;    // Indicates if the plant has been watered.
    int growthStage;   // Represents the growth stage of the plant.

public:
    /**
     * Constructor that initializes the plant with a name and sets initial states.
     * @param name The name of the plant.
     */
    Plant(const std::string& name);

    /**
     * Performs maintenance on the plant, including checking if it is watered.
     */
    void performMaintenance() const override;

    /**
     * Gets the current condition of the plant, including its growth stage.
     * @return A string describing the current growth stage of the plant.
     */
    std::string getCondition() const override;

    /**
     * Water the plant. This method sets isWatered to true.
     */
    void water();

    /**
     * Increases the growth stage of the plant.
     */
    void grow();

    /**
     * Prunes the plant. This method could affect the growth stage or other attributes.
     */
    void prune();
};

#endif /* PLANT_H_ */
