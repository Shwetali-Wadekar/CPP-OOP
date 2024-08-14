/*
 * Customer.cpp
 *
 *  Created on: Jul 29, 2024
 *      Author: pradh
 */

#include "Customer.h"
    //std::vector<std::unique_ptr<Order>> orders;

Customer::Customer(const std::string &name) : name(name)
{
}

void Customer::addOrder(std::unique_ptr<Order> order)
{
	orders.push_back(std::move(order));
}

std::string Customer::getName() const
{
	return this->name;
}

float Customer::getTotalOrderQuantity() const
{	float itemsQty=0;
	for(auto iter = orders.begin() ; iter != orders.end() ; ++iter) {
		itemsQty= itemsQty+(**iter).getTotalQuantity();
	}
	return itemsQty;
}
//Customer::Customer()
//{
//	// TODO Auto-generated constructor stub
//
//}
//
//Customer::~Customer()
//{
//	// TODO Auto-generated destructor stub
//}
//
