/*
 * ElectronicItem.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "ElectronicItem.h"
#include <iostream>
using namespace std;
ElectronicItem::ElectronicItem(const std::string &itemId,
		const std::string &name, const std::string &description,
		double startingPrice):
		Item(itemId,name,description,startingPrice)
{
}

std::string ElectronicItem::getItemType() const
{
	return this->itemType;
}

void ElectronicItem::displayInfo() const
{
	Item::displayInfo();
	cout<<" Item Type:"<<this->itemType;
}

