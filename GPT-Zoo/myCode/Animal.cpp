/*
 * Animal.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Animal.h"

Animal::Animal(std::string name, int age) : name(name) , age(age)
{
}

std::string Animal::getName() const
{
	return this->name;
}

int Animal::getAge() const
{
	return this->age;
}
