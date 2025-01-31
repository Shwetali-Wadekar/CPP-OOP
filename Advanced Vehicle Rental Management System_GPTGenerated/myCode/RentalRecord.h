#ifndef RENTALRECORD_H_
#define RENTALRECORD_H_

#include <string>
#include <Poco/DateTime.h>
#include "Vehicle.h"
#include "Customer.h"

/**
 * Represents a rental record in the vehicle rental system.
 */
class RentalRecord {
private:
    Vehicle* vehicle;
    Customer* customer;
    Poco::DateTime rentalDate;
    Poco::DateTime returnDate;

public:
    /**
     * Initializes a new rental record with the given vehicle, customer, rental date, and return date.
     *
     * @param vehicle the rented vehicle
     * @param customer the customer who rented the vehicle
     * @param rentalDate the date of rental
     * @param returnDate the date of return
     */
    RentalRecord(Vehicle* vehicle, Customer* customer, const Poco::DateTime& rentalDate, const Poco::DateTime& returnDate);

    /**
     * Returns the rented vehicle.
     *
     * @return the rented vehicle
     */
    Vehicle* getVehicle() const;

    /**
     * Returns the customer who rented the vehicle.
     *
     * @return the customer
     */
    Customer* getCustomer() const;

    /**
     * Returns the rental date.
     *
     * @return the rental date
     */
    Poco::DateTime getRentalDate() const;

    /**
     * Returns the return date.
     *
     * @return the return date
     */
    Poco::DateTime getReturnDate() const;

    /**
     * Calculates the total rental duration in days.
     *
     * @return the rental duration in days
     */
    int calculateRentalDuration() const;
};

#endif /* RENTALRECORD_H_ */
