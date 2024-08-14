/*
 * Resistor.cpp
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#include "Resistor.h"

Resistor::Resistor(std::string name) : name(name)
{
	// TODO Auto-generated constructor stub

}

std::string Resistor::getName() const
{
	return name;
}

std::string Resistor::toString() const
{
	return getName()+"="+std::to_string(nominalValue())+" Ohm";
}

Resistor::~Resistor()
{
	// TODO Auto-generated destructor stub
}

std::ostream& operator <<(std::ostream& lhs, Resistor& rhs)
{
	lhs<<rhs.toString();
	return lhs;
}

void Resistor::write(std::ostream &out)
{
	out<<name+";";
}
