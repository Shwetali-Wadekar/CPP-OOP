/*
 * GardenElement.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef GARDENELEMENT_H_
#define GARDENELEMENT_H_



#include <string>
#include <memory>

/**
 * Abstract base class for all garden elements.
 */
class GardenElement {
protected:
    std::string elementName;

public:
    /**
     * Constructor that initializes the name of the garden element.
     * @param name The name of the garden element.
     */
    GardenElement(const std::string& name);

    /**
     * Virtual destructor to allow proper cleanup of derived classes.
     */
    virtual ~GardenElement();

    /**
     * Gets the name of the garden element.
     * @return The name of the garden element.
     */
    std::string getName() const;

    /**
     * Abstract method to perform maintenance on the garden element.
     * Derived classes must implement this method to provide maintenance logic.
     */
    virtual void performMaintenance() const = 0;

    /**
     * Abstract method to get the current condition of the garden element.
     * Derived classes must implement this method to provide the condition string.
     * @return A string describing the current condition of the garden element.
     */
    virtual std::string getCondition() const = 0;
};
#endif /* GARDENELEMENT_H_ */
