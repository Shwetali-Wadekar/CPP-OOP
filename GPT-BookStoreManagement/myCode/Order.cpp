/*
 * Order.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Order.h"
Order::Order(const ShoppingCart &cart, const string &orderId) : orderId(orderId)
{

	this->books=cart.getBooks();
	this->orderDate = time(0);
	this->totalCost= cart.getTotalCost();
}

string Order::getOrderId() const
{
	return this->orderId;
}

double Order::getTotalCost() const
{
	return this->totalCost;
}

time_t Order::getOrderDate() const
{
	return this->orderDate;
}

vector<Book*> Order::getBooks() const
{
	return this->books;
}
