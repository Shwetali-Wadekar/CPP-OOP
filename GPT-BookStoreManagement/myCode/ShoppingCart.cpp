/*
 * ShoppingCart.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	totalCost=0;
}

void ShoppingCart::addBook(Book *book)
{
	this->cart.push_back(book);
	this->totalCost=this->totalCost+book->getPrice();
}

void ShoppingCart::removeBook(const string &isbn)
{
	auto foundIter= cart.begin();
	bool flag=false;
	for(auto iter = cart.begin() ; iter != cart.end() ; ++iter) {
		if((*iter)->getIsbn()==isbn) {
			flag=true;
			foundIter=iter;
		}
	}
	if(flag) {
		this->totalCost=totalCost-(*foundIter)->getPrice();

		cart.erase(foundIter);
	}
}

double ShoppingCart::getTotalCost() const
{
	return this->totalCost;
}

vector<Book*> ShoppingCart::getBooks() const
{
	return this->cart;
}

void ShoppingCart::clearCart()
{
	cart.clear();
}
