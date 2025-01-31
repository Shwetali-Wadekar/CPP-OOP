/*
 * InventoryManager.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "InventoryManager.h"
#include<sstream>
#include<iostream>
using namespace std;

//    std::vector<std::unique_ptr<Warehouse>> warehouses;

void InventoryManager::addWarehouse(std::unique_ptr<Warehouse> warehouse)
{
	warehouses.push_back(move(warehouse));
}

Warehouse* InventoryManager::findWarehouseByName(const std::string &name)
{
	for(auto iter=warehouses.begin() ; iter != warehouses.end() ; ++iter) {
		if((*iter)->getName()==name) {
			return (*iter).get();
		}
	}
	return nullptr;
}

std::string InventoryManager::generateProductReport() const
{
	ostringstream oss;
	for(auto iter=warehouses.begin() ; iter != warehouses.end() ; ++iter) {
		auto all_products=(*iter)->allproducts();
		oss<<"warehouse: "<<(*iter)->getName()<<endl;
		for(auto i= all_products.begin() ; i != all_products.end() ; ++i) {
			oss<<(*i)->getProductId()<<"; "<<(*i)->getName()<<"; "<<(*i)->getPrice()<<endl;
		}
	}
	return oss.str();
}

float InventoryManager::calculateTotalValue() const
{
	float total;

	for(auto iter=warehouses.begin() ; iter != warehouses.end() ; ++iter) {
		auto all_products=(*iter)->allproducts();
		for(auto i= all_products.begin() ; i != all_products.end() ; ++i) {
			total=total+(*i)->getPrice();
		}
	}
	return total;


}
