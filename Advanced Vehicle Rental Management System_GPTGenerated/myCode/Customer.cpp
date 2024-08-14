/*
 * Customer.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "Customer.h"

Customer::Customer(const std::string &name, const std::string &customerID) : name(name) , customerID(customerID)
{
}

std::string Customer::getName() const
{
	return name;
}

std::string Customer::getCustomerID() const
{
	return this->customerID;
}
