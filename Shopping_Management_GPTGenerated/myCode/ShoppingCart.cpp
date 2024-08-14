/*
 * ShoppingCart.cpp
 *
 *  Created on: Jul 29, 2024
 *      Author: pradh
 */
#include <algorithm>
#include "ShoppingCart.h"
#include<stdexcept>
//    std::vector<std::unique_ptr<Item>> items;

void ShoppingCart::addItem(std::unique_ptr<Item> item)
{
	items.push_back(std::move(item));
}
//     * @throws std::runtime_error if the item is not found.

void ShoppingCart::removeItem(const std::string &name)
{
	bool foundFlag=false;
	auto foundIter=items.begin();
	for(auto iter = items.begin() ; iter != items.end() ; ++iter) {
		if((**iter).getName() == name)	{
			foundIter=iter;
			foundFlag=true;
			break;
		}
	}

	if(foundFlag){
		items.erase(foundIter);
	}else {
		throw std::runtime_error ("Item not found in shoppingcart");
	}
}

float ShoppingCart::getTotalQuantity() const
{
	return items.size();
}
	//ShoppingCart::ShoppingCart()
	//{
	//	// TODO Auto-generated constructor stub
	//
	//}
	//
	//ShoppingCart::~ShoppingCart()
	//{
	//	// TODO Auto-generated destructor stub
	//}
	//
