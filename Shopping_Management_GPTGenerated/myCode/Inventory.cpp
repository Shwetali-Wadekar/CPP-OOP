/*
 * Inventory.cpp
 *
 *  Created on: Jul 29, 2024
 *      Author: pradh
 */

#include "Inventory.h"
    //std::map<std::string, float> stock;

void Inventory::addStock(const std::string &name, float quantity)
{
	stock[name]=quantity;
}

void Inventory::removeStock(const std::string &name, float quantity)
{
	stock.erase(name);
}

float Inventory::getStock(const std::string &name) const
{
	return stock.at(name);
}
//Inventory::Inventory()
//{
//	// TODO Auto-generated constructor stub
//
//}
//
//Inventory::~Inventory()
//{
//	// TODO Auto-generated destructor stub
//}
//
