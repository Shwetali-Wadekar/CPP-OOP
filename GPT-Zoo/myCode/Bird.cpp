/*
 * Bird.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Bird.h"

Bird::Bird(std::string name, int age, bool canFly) : Animal(name,age) , canFly(canFly)
{
}

std::string Bird::makeSound() const
{
	return "Bro I am Bird";
}

bool Bird::getCanFly() const
{
	return this->canFly;
}
