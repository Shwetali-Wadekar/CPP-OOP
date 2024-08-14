#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>

/**
 * Represents a general vehicle with a make, model, registration number, and rental status.
 */
class Vehicle {
private:
    std::string make;
    std::string model;
    std::string registrationNumber;
    bool isAvailable;

public:
    /**
     * Initializes a new vehicle with the given make, model, and registration number.
     *
     * @param make the vehicle's make
     * @param model the vehicle's model
     * @param registrationNumber the vehicle's registration number
     * @param isAvailable the availability status of the vehicle
     */
    Vehicle(const std::string& make, const std::string& model, const std::string& registrationNumber, bool isAvailable = true);

    /**
     * Returns the vehicle's make.
     *
     * @return the vehicle's make
     */
    std::string getMake() const;

    /**
     * Returns the vehicle's model.
     *
     * @return the vehicle's model
     */
    std::string getModel() const;

    /**
     * Returns the vehicle's registration number.
     *
     * @return the vehicle's registration number
     */
    std::string getRegistrationNumber() const;

    /**
     * Returns the vehicle's availability status.
     *
     * @return true if the vehicle is available, false otherwise
     */
    bool getAvailability() const;

    /**
     * Sets the vehicle's availability status.
     *
     * @param availability the new availability status
     */
    void setAvailability(bool availability);
};

#endif /* VEHICLE_H_ */
