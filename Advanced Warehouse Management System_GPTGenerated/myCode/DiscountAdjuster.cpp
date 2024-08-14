/*
 * DiscountAdjuster.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "DiscountAdjuster.h"
//    std::map<std::string, float> discounts; // product ID to discount percentage

DiscountAdjuster& DiscountAdjuster::addDiscount(const std::string &productId,
		float discount)
{
	discounts.insert(std::make_pair(productId,discount));
	return *this;
}

float DiscountAdjuster::adjust(const Product &product) const
{
	//float discount=
	auto discount=discounts.find(product.getProductId());
	float discountAmout=0;
	if(discount!=discounts.end()) {
		discountAmout=discount->second;
	}

	float price=product.getPrice();
	float adjustedPrice=price-price*discountAmout;
	return adjustedPrice;

}
