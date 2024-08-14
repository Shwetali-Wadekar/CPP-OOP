/*
 * Shop.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include <list>
#include <stdexcept>

#include "Shop.h"
#include "ShoppingList.h"
#include "Item.h"
#include "Discount.h"

using namespace std;

Shop::Shop(std::string name) : name{name} {
}

std::string Shop::getName() const {
	return name;
}

Shop& Shop::addProduct(const Product &product) {

	products.insert(make_pair(product.getName(),product));

	// TODO (add code)

	return *this;
}

Shop& Shop::setBasePrice(std::string productName, float basePrice) {
	// TODO (add code)

	auto productIter=products.find(productName);

	if(productIter != products.end()) {
		productIter->second.setBasePrice(basePrice);
	}else {
		throw invalid_argument ("product not found");
	}


	return *this;
}


//
//Shop& Shop::setBasePrice(std::string productName, float basePrice) {
//	// TODO (add code)
//
//	for(auto& member: products){
//		if(productName == member.first){
//		member.second.setBasePrice(basePrice);
//		} else
//			throw std::invalid_argument("product not found");
//	}
//
//	return *this;
//}


Shop& Shop::setDiscount(std::string productName,
		std::shared_ptr<Discount> discount) {
	// TODO (add code)

	auto productIter=products.find(productName);

		if(productIter != products.end()) {
			productIter->second.setDiscount(discount);
		}else {
			throw invalid_argument ("product not found");
		}


	return *this;
}

float Shop::calculatePurchase(const ShoppingList& shoppingList,
		std::set<const Item*>& notAvailable) const {
	// TODO (add code/replace "dummy return")


	std::list<Item>::const_iterator begin;
	std::list<Item>::const_iterator end;

	shoppingList.items(begin,end);
	float totalamount=0;

	for( auto i= begin; i!= end ; ++i) {
		auto finditer = products.find(i->getName());

		if( finditer != products.end()) {

			totalamount= totalamount+finditer->second.priceFor(i->getQuantity());
		} else {
			Item* itt=new Item(*i);

			notAvailable.insert(itt);

		}

	}


	return totalamount;
}

