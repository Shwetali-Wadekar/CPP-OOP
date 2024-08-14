/*
 * Buyer.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Buyer.h"

#include<iostream>

using namespace std;

Buyer::Buyer(const std::string &userId, const std::string &name,
		const std::string &email, double balance) :
		User(userId,name,email,balance)
{
}

std::string Buyer::getUserRole() const
{
	return this->role;
}

void Buyer::displayInfo() const
{
	User::displayInfo();
	cout<<" Role:"<<this->role;
}
