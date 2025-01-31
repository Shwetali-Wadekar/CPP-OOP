/*
 * Bid.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Bid.h"

Bid::Bid(const std::shared_ptr<User> &user, double amount) : user(user) , amount(amount)
{
}

std::shared_ptr<User> Bid::getUser() const
{
	return this->user;
}

double Bid::getAmount() const
{
	return this->amount;
}

std::shared_ptr<Poco::JSON::Object> Bid::toJson() const
{
	std::shared_ptr<Poco::JSON::Object> returnptr=user->toJson();
	returnptr->set("amount",this->amount);

	return returnptr;
}
