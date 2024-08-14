/*
 * QuantityDiscount.cpp
 *
 *  Created on: 11.02.2024
 *      Author: mnl
 */

#include "QuantityDiscount.h"
using namespace std;
QuantityDiscount& QuantityDiscount::addLimit(float quantity, float discount) {
	// TODO (add code)

	limits.insert(make_pair(quantity,discount));
	return *this;
}

/**
 * Evaluates the discount for the given (requested) quantity.
 * The discount is 0 if the requested quantity is smaller than
 * the quantity of the limit with the smallest quantity (see
 * method addLimit). Else the discount is used from the limit
 * with the largest quantity that is smaller or equal to
 * the requested quantity.
 * (4 points)
 *
 * @param quantity the quantity that the customer buys (requests)
 * @return the discount, a value in the range [0, 1)
 */
float QuantityDiscount::discountFor(float quantity) const {
	// TODO (add code/replace dummy return)
	if( quantity<limits.begin()->first ) {
		return 0;
	}else{
		auto it2= limits.rbegin();
		for(auto iter = limits.rbegin() ; iter != limits.rend() ; ++iter ) {

			if(quantity >= iter->first) {

				it2=iter;
				break;
			}

		}
		return it2->second;

	}


	//return 0;
}
