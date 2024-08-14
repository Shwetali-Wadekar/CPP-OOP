/*
 * Item.cpp
 *
 *  Created on: Jul 29, 2024
 *      Author: pradh
 */

#include "Item.h"

Item::Item(const std::string &name, double price) : name(name) , price(price)
{
}

std::string Item::getName() const
{
	return name;
}

double Item::getPrice() const
{
	return price;
}
//Item::Item()
//{
//	// TODO Auto-generated constructor stub
//
//}
//
//Item::~Item()
//{
//	// TODO Auto-generated destructor stub
//}
//
