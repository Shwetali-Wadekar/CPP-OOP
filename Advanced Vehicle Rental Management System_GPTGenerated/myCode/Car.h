#ifndef CAR_H_
#define CAR_H_

#include "Vehicle.h"

/**
 * Represents a car which is a type of vehicle. Inherits from Vehicle.
 */
class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    /**
     * Initializes a new car with the given make, model, registration number, and number of doors.
     *
     * @param make the car's make
     * @param model the car's model
     * @param registrationNumber the car's registration number
     * @param numberOfDoors the number of doors in the car
     */
    Car(const std::string& make, const std::string& model, const std::string& registrationNumber, int numberOfDoors);

    /**
     * Returns the number of doors in the car.
     *
     * @return the number of doors
     */
    int getNumberOfDoors() const;
};

#endif /* CAR_H_ */
