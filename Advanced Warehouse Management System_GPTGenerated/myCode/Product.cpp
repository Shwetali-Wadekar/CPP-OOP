/*
 * Product.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "Product.h"

Product::Product(const std::string &name, const std::string &productId,
		float price) : name(name), productId(productId) , price(price)
{
}

std::string Product::getName() const
{
	return name;

}

std::string Product::getProductId() const
{
	return productId;
}

float Product::getPrice() const
{
	return price;
}

void Product::setPrice(float price)
{
	this->price=price;
}
