/*
 * RentalRecord.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "RentalRecord.h"

RentalRecord::RentalRecord(Vehicle *vehicle, Customer *customer,
		const Poco::DateTime &rentalDate, const Poco::DateTime &returnDate)
: vehicle(vehicle) , customer(customer) , rentalDate(rentalDate) , returnDate(returnDate)
{
}

Vehicle* RentalRecord::getVehicle() const
{
	return this->vehicle;
}

Customer* RentalRecord::getCustomer() const
{
	return this->customer;
}

Poco::DateTime RentalRecord::getRentalDate() const
{
	return this->rentalDate;
}

Poco::DateTime RentalRecord::getReturnDate() const
{
	return this->returnDate;
}

int RentalRecord::calculateRentalDuration() const
{
	Poco::Timespan duration = this->returnDate-this->rentalDate;
	return duration.days();
}
