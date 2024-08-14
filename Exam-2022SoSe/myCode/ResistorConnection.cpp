/*
 * ResistorConnection.cpp
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#include "ResistorConnection.h"
#include<iostream>
#include<iomanip>

ResistorConnection::ResistorConnection(std::string name) : Resistor(name)
{
	// TODO Auto-generated constructor stub

}

char ResistorConnection::separator() const
{
	return ',';
}

std::string ResistorConnection::getName() const
{
	std::string first= Resistor::getName()+"[";
	std::string connectionResistors="";
	for( auto i= resistors.begin() ; i != resistors.end() ; ++i) {
		connectionResistors=connectionResistors+(**i).getName()+separator();
	}
	return first+connectionResistors.substr(0,connectionResistors.size()-1)+"]";


}

ResistorConnection& ResistorConnection::operator +=(
		const std::shared_ptr<Resistor> &resistor)
{
	resistors.push_back(resistor);
	return *this;
}

void ResistorConnection::write(std::ostream &out)
{
	float tolerance= (maximumValue()-nominalValue())/nominalValue();

	for(auto i= resistors.begin() ; i != resistors.end() ; ++i) {

		(**i).write(out);
		//out<<std::endl;

	}

		std::ostringstream oss;
		oss<<std::setprecision(6)<<nominalValue()<<";"<<tolerance;
	out<<getName()+";"+oss.str()<<std::endl;
}
