/*
 * OrderManager.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "OrderManager.h"
#include<stdexcept>
#include<set>

void OrderManager::addOrder(unique_ptr<Order> order)
{
	auto found = orders.find(order->getOrderId());

	if( found != orders.end() ) {
		throw std::runtime_error("orderID already exist in the OrderManager");
	}else {
		orders.insert(std::make_pair(order->getOrderId(),std::move(order)));
	}
}

void OrderManager::removeOrder(const string &orderId)
{
	auto found = orders.find(orderId);
	if( found != orders.end() ) {
		orders.erase(orderId);
}
}

Order* OrderManager::searchByOrderId(const string &orderId) const
{
	auto found = orders.find(orderId);
	if( found != orders.end() ) {
		return found->second.get();
	}

	return nullptr;


}

vector<Order*> OrderManager::getAllOrdersSortedByDate() const
{
	std::map<time_t,Order*> orderWithDate;
	set<time_t> times;
	vector<Order*> sortedOrders;

	for(auto iter = orders.begin() ; iter != orders.end() ; ++iter) {
		times.insert((*iter).second->getOrderDate());
	}


	for(auto iter = times.begin() ; iter != times.end() ; ++iter) {

		for(auto i = orders.begin() ; i != orders.end() ; ++i) {
			if( (*iter)==(*i).second->getOrderDate()) {
				sortedOrders.push_back((*i).second.get());
			}
		}
	}

	return sortedOrders;
}
