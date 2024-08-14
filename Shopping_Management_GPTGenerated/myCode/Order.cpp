/*
 * Order.cpp
 *
 *  Created on: Jul 29, 2024
 *      Author: pradh
 */

#include "Order.h"
#include<stdexcept>
//    std::list<std::unique_ptr<Item>> orderItems;

void Order::addItem(std::unique_ptr<Item> item)
{
	orderItems.push_back(std::move(item));
}

void Order::removeItem(const std::string &name)
{
	bool foundFlag=false;
	auto foundIter=orderItems.begin();
	for(auto iter = orderItems.begin() ; iter != orderItems.end() ; ++iter) {
		if((**iter).getName() == name)	{
			foundIter=iter;
			foundFlag=true;
			break;
		}
	}

	if(foundFlag){
		orderItems.erase(foundIter);
	}else {
		throw std::runtime_error ("Item not found in shoppingcart");
	}
}

float Order::getTotalQuantity() const
{
	return orderItems.size();

}
//Order::Order()
//{
//	// TODO Auto-generated constructor stub
//
//}
//
//Order::~Order()
//{
//	// TODO Auto-generated destructor stub
//}
//
