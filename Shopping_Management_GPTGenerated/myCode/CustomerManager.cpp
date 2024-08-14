/*
 * CustomerManager.cpp
 *
 *  Created on: Jul 29, 2024
 *      Author: pradh
 */

#include "CustomerManager.h"

//    std::map<std::string, std::unique_ptr<Customer>> customerMap;

void CustomerManager::addCustomer(std::unique_ptr<Customer> customer)
{
	customerMap.insert(std::make_pair(customer->getName(),std::move(customer)));
}

Customer* CustomerManager::getCustomer(const std::string &name) const
{
	return customerMap.at(name).get();
}
//CustomerManager::CustomerManager()
//{
//	// TODO Auto-generated constructor stub
//
//}
//
//CustomerManager::~CustomerManager()
//{
//	// TODO Auto-generated destructor stub
//}
//
