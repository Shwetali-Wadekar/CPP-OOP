/*
 * Gardener.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef GARDENER_H_
#define GARDENER_H_


#include <string>
#include <vector>
#include <memory>
#include <map>
#include "GardenElement.h"

/**
 * Represents a gardener responsible for managing garden elements.
 */
class Gardener {
private:
    std::string gardenerName;  // The name of the gardener.
    std::map<std::string, std::shared_ptr<GardenElement>> elements; // Map of garden elements by name.

public:
    /**
     * Constructor that initializes the gardener with a name.
     * @param name The name of the gardener.
     */
    Gardener(const std::string& name);

    /**
     * Gets the name of the gardener.
     * @return The name of the gardener.
     */
    std::string getName() const;

    /**
     * Adds a garden element to the gardener's list.
     * @param element A shared pointer to the garden element to be added.
     */
    void addElement(const std::shared_ptr<GardenElement>& element);

    /**
     * Removes a garden element from the gardener's list by name.
     * @param name The name of the garden element to be removed.
     */
    void removeElement(const std::string& name);

    /**
     * Performs maintenance on all garden elements managed by the gardener.
     */
    void performMaintenance() const;

    /**
     * Lists all garden elements managed by the gardener with their current conditions.
     */
    void listElements() const;

    /**
     * Updates the condition of a garden element.
     * @param name The name of the garden element whose condition needs updating.
     * @param newCondition The new condition string for the garden element.
     */
    void updateElementCondition(const std::string& name, const std::string& newCondition);
};

#endif /* GARDENER_H_ */
