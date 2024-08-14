#ifndef VEHICLERENTALSYSTEM_H_
#define VEHICLERENTALSYSTEM_H_

#include <vector>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

/**
 * Represents a vehicle rental system.
 */
class VehicleRentalSystem {
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    std::map<std::string, Vehicle*> rentedVehicles;

public:
    /**
     * Adds a vehicle to the rental system.
     *
     * @param vehicle the vehicle to add
     */
    VehicleRentalSystem& addVehicle(std::unique_ptr<Vehicle> vehicle);

    /**
     * Finds a vehicle by its registration number.
     *
     * @param registrationNumber the registration number of the vehicle
     * @return a pointer to the vehicle if found, nullptr otherwise
     */
    Vehicle* findVehicleByRegistrationNumber(const std::string& registrationNumber);

    /**
     * Rents a vehicle to a customer.
     *
     * @param registrationNumber the registration number of the vehicle
     * @param customerID the ID of the customer
     * @throws std::invalid_argument if the vehicle is not available or does not exist
     */
    void rentVehicle(const std::string& registrationNumber, const std::string& customerID);

    /**
     * Returns a rented vehicle.
     *
     * @param registrationNumber the registration number of the vehicle
     * @param customerID the ID of the customer
     * @throws std::invalid_argument if the vehicle is not rented by the customer
     */
    void returnVehicle(const std::string& registrationNumber, const std::string& customerID);

    /**
     * Lists all available vehicles.
     *
     * @return a vector of pointers to available vehicles
     */
    std::vector<Vehicle*> listAvailableVehicles();
};

#endif /* VEHICLERENTALSYSTEM_H_ */
