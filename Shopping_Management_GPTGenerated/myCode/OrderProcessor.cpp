/*
 * OrderProcessor.cpp
 *
 *  Created on: Jul 29, 2024
 *      Author: pradh
 */

#include "OrderProcessor.h"
//    std::vector<std::unique_ptr<Customer>> customers;

void OrderProcessor::addCustomer(std::unique_ptr<Customer> customer)
{
	customers.push_back(std::move(customer));
}

void OrderProcessor::processOrders(const std::string &name)
{

}

float OrderProcessor::getTotalQuantity() const
{	float itemsQty=0;
	for(auto iter = customers.begin() ; iter != customers.end() ; ++iter) {
		itemsQty= itemsQty+(**iter).getTotalOrderQuantity();
	}
	return itemsQty;
}
//OrderProcessor::OrderProcessor()
//{
//	// TODO Auto-generated constructor stub
//
//}
//
//OrderProcessor::~OrderProcessor()
//{
//	// TODO Auto-generated destructor stub
//}
//
