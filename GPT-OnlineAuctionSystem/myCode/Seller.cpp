/*
 * Seller.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Seller.h"
#include<iostream>

using namespace std;

Seller::Seller(const std::string &userId, const std::string &name,
		const std::string &email, double balance) :
		User(userId,name,email,balance)
{
}

std::string Seller::getUserRole() const
{
	return this->role;
}

void Seller::displayInfo() const
{
	User::displayInfo();
	cout<<" Role:"<<this->role;
}
