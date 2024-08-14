/*
 * TransportCompany.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef TRANSPORTCOMPANY_H_
#define TRANSPORTCOMPANY_H_


#include <string>
#include <memory>
#include <map>

class Fleet;

/**
 * Represents a transportation company managing a fleet of vehicles.
 */
class TransportCompany {
private:
    std::string name;
    std::shared_ptr<Fleet> fleet;

public:
    /**
     * Initializes a new instance with the given name and fleet.
     *
     * @param name the company's name
     * @param fleet the fleet managed by the company
     */
    TransportCompany(std::string name, std::shared_ptr<Fleet> fleet);  // Constructor implementation

    /**
     * Returns the company's name.
     *
     * @return the name
     */
    std::string getName() const;  // Implement to return the company's name

    /**
     * Calculates the total mileage of the company's fleet.
     *
     * @return the total mileage
     */
    float totalFleetMileage() const;  // Implement to return the total mileage of the fleet

    /**
     * Calculates the total capacity of the company's fleet.
     *
     * @return the total capacity
     */
    int totalFleetCapacity() const;  // Implement to return the total capacity of the fleet
};


#endif /* TRANSPORTCOMPANY_H_ */
