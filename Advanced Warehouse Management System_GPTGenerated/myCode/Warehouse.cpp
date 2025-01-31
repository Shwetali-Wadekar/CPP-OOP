/*
 * Warehouse.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "Warehouse.h"
#include<stdexcept>
Warehouse::Warehouse(const std::string &name) :name(name)
{
}

std::string Warehouse::getName() const
{
	return name;
}

void Warehouse::addProduct(std::unique_ptr<Product> product)
{
	products.push_back(std::move(product));
}

void Warehouse::removeProduct(const std::string &productId)
{
	auto foundIter=products.begin();
	bool flag=0;
	for(auto iter=products.begin() ; iter != products.end() ; ++iter) {
		if((*iter)->getProductId()==productId) {
			flag=1;
			foundIter=iter;
		}
	}
	if(flag){
		products.erase(foundIter);
	}else {
		throw std::invalid_argument ("product not found");
	}
}

Product* Warehouse::findProductById(const std::string &productId)
{
	for(auto iter=products.begin() ; iter != products.end() ; ++iter) {
		if((*iter)->getProductId()==productId) {
			return (*iter).get();
		}

	}
	return nullptr;
}

std::vector<Product*> Warehouse::allproducts()
{
	std::vector<Product*> all_products;

	for(auto iter = products.begin() ; iter != products.end() ; ++iter) {
		all_products.push_back((*iter).get());
	}

	return all_products;
}
