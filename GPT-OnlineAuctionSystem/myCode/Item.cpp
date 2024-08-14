/*
 * Item.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Item.h"
#include <iostream>
using namespace std;
Item::Item(const std::string &itemId, const std::string &name,
		const std::string &description, double startingPrice) : itemId(itemId) , name(name),
		description(description) , startingPrice(startingPrice)
{
}

std::string Item::getItemId() const
{
	return this->itemId;
}

void Item::displayInfo() const
{
	std::cout<<"Id:"<<this->itemId<<", Name:"<<this->name<<", Description:"<<this->description<<", Starting Price:"<<this->startingPrice;
}

std::shared_ptr<Poco::JSON::Object> Item::toJson() const
{
	shared_ptr<Poco::JSON::Object> returnptr(new Poco::JSON::Object);

	returnptr->set("Id",this->itemId);
	returnptr->set("Name",this->name);
	returnptr->set("Description",this->description);
	returnptr->set("Starting Price",this->startingPrice);


	return returnptr;
}

double Item::getStartingPrice() const
{
	return this->startingPrice;
}
