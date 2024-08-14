/*
 * SerialResistorConnection.cpp
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#include "SerialResistorConnection.h"

SerialResistorConnection::SerialResistorConnection(std::string name) : ResistorConnection(name)
{
	// TODO Auto-generated constructor stub

}

char SerialResistorConnection::separator() const
{
	return '-';
}

float SerialResistorConnection::nominalValue() const
{
	float nominalvalue=0;
	for(auto i= resistors.begin(); i != resistors.end() ; ++i) {

		nominalvalue= nominalvalue+(**i).nominalValue();

	}

	return nominalvalue;
}

float SerialResistorConnection::maximumValue() const
{
	float maximumvalue=0;
	for(auto i= resistors.begin(); i != resistors.end() ; ++i) {

		maximumvalue= maximumvalue +(**i).maximumValue();

	}

	return maximumvalue;
}

float SerialResistorConnection::minimumValue() const
{
	float minimumvalue=0;
	for(auto i= resistors.begin(); i != resistors.end() ; ++i) {

		minimumvalue= minimumvalue+(**i).minimumValue();

	}

	return minimumvalue;
}
