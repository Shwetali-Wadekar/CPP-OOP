/*
 * AntiqueItem.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "AntiqueItem.h"
#include <iostream>
using namespace std;
AntiqueItem::AntiqueItem(const std::string &itemId, const std::string &name,
		const std::string &description, double startingPrice) :
		Item(itemId,name,description,startingPrice)
{
}

std::string AntiqueItem::getItemType() const
{
	return this->itemType;
}

void AntiqueItem::displayInfo() const
{
	Item::displayInfo();
	cout<<" Item Type:"<<this->itemType;
}
