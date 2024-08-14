/*
 * InfrastructureElement.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef INFRASTRUCTUREELEMENT_H_
#define INFRASTRUCTUREELEMENT_H_


#include <string>
#include <memory>

/**
 * Abstract base class for all infrastructure elements.
 */
class InfrastructureElement {
protected:
    std::string elementID;  // Unique identifier for the element.
    std::string location;   // Location of the element.

public:
    /**
     * Constructor for the InfrastructureElement class.
     *
     * @param id Unique identifier for the element.
     * @param loc Location of the element.
     */
    InfrastructureElement(const std::string& id, const std::string& loc);

    /**
     * Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~InfrastructureElement();

    /**
     * Get the ID of the infrastructure element.
     *
     * @return The ID of the element as a string.
     */
    std::string getID() const;

    /**
     * Get the location of the infrastructure element.
     *
     * @return The location of the element as a string.
     */
    std::string getLocation() const;

    /**
     * Abstract method to perform maintenance on the infrastructure element.
     * Derived classes should implement the maintenance logic.
     */
    virtual void performMaintenance() const = 0;

    /**
     * Abstract method to get the status of the infrastructure element.
     * Derived classes should provide specific status information.
     *
     * @return A string describing the current status of the element.
     */
    virtual std::string getStatus() const = 0;
};

#endif /* INFRASTRUCTUREELEMENT_H_ */
