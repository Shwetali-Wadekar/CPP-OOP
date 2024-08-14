/*
 * ShopDb.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include "ShopDb.h"
#include "Shop.h"

using namespace std;

ShopDb& ShopDb::addShop(std::unique_ptr<Shop>&& shop) {
	// TODO (add code)
	string shopname=shop.get()->getName();
	this->knownShops.insert(make_pair(shopname,move(shop)));

	return *this;
}

vector<Shop*> ShopDb::shops() const {
	// TODO (add code/replace "dummy return")
	vector<Shop*> shop_vector;

	for(auto iter= knownShops.begin() ; iter != knownShops.end() ; ++iter) {

		shop_vector.push_back(iter->second.get());
	}



	return shop_vector;
	//turn vector<Shop*>();
}

Shop* ShopDb::shopByName(std::string name) {
	// TODO (add code/replace "dummy return")

	auto finditer= knownShops.find(name);
	if(finditer != knownShops.end()) {

		return finditer->second.get();



	}else {
		return nullptr;
	}


	return nullptr;
}
