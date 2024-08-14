/*
 * Mammal.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Mammal.h"

Mammal::Mammal(std::string name, int age, bool hasFur) : Animal(name,age) , hasFur(hasFur)
{
}

std::string Mammal::makeSound() const
{
	return "Bro I am Mammal";
}

bool Mammal::getHasFur() const
{
	return this->hasFur;
}
