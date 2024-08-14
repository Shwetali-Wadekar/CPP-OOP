/*
 * ParallelResistorConnection.cpp
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#include "ParallelResistorConnection.h"



ParallelResistorConnection::ParallelResistorConnection(std::string name) : ResistorConnection(name)
{
}

char ParallelResistorConnection::separator() const
{
	return '|';
}

float ParallelResistorConnection::nominalValue() const
{
	float nominalvalue=0;
	for(auto i= resistors.begin(); i != resistors.end() ; ++i) {

		if(i==resistors.begin()) {
		nominalvalue = ((**i).nominalValue());
		}else{
			nominalvalue = (1/nominalvalue)+(1/(**i).nominalValue());

		}

	}

	return (1/nominalvalue);
}

float ParallelResistorConnection::maximumValue() const
{
	float maxvalue=0;
	for(auto i= resistors.begin(); i != resistors.end() ; ++i) {

		if(i==resistors.begin()) {
			maxvalue = ((**i).maximumValue());
		}else{
			maxvalue = (1/maxvalue)+(1/(**i).maximumValue());

		}

	}

	return (1/maxvalue);
}

float ParallelResistorConnection::minimumValue() const
{
	float minimumvalue=0;
	for(auto i= resistors.begin(); i != resistors.end() ; ++i) {

		if(i==resistors.begin()) {
			minimumvalue = ((**i).minimumValue());
		}else{
			minimumvalue = (1/minimumvalue)+(1/(**i).minimumValue());

		}

	}

	return (1/minimumvalue);
}

