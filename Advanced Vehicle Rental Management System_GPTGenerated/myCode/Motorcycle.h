#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_

#include "Vehicle.h"

/**
 * Represents a motorcycle which is a type of vehicle. Inherits from Vehicle.
 */
class Motorcycle : public Vehicle {
private:
    int engineCapacity;

public:
    /**
     * Initializes a new motorcycle with the given make, model, registration number, and engine capacity.
     *
     * @param make the motorcycle's make
     * @param model the motorcycle's model
     * @param registrationNumber the motorcycle's registration number
     * @param engineCapacity the engine capacity of the motorcycle in cc
     */
    Motorcycle(const std::string& make, const std::string& model, const std::string& registrationNumber, int engineCapacity);

    /**
     * Returns the engine capacity of the motorcycle.
     *
     * @return the engine capacity in cc
     */
    int getEngineCapacity() const;
};

#endif /* MOTORCYCLE_H_ */
