/*
 * ResistorPart.cpp
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#include "ResistorPart.h"
#include <sstream>
#include<iomanip>
ResistorPart::ResistorPart(std::string name, float value,float tolerance) : Resistor(name), value(value) , tolerance(tolerance)
{
	// TODO Auto-generated constructor stub

}

float ResistorPart::nominalValue() const
{
	return value;
}

float ResistorPart::maximumValue() const
{
	return value+value*tolerance;
}

float ResistorPart::minimumValue() const
{
	return value-value*tolerance;
}

void ResistorPart::write(std::ostream &out)
{
	float tolerance= (maximumValue()-nominalValue())/nominalValue();
	Resistor::write(out);

	std::ostringstream oss;
	oss<<std::setprecision(6)<<nominalValue()<<";"<<tolerance;
	out<<oss.str()<<std::endl;
}

ResistorPart::ResistorPtr ResistorPart::from(std::string line)
{
	std::istringstream iss(line);
	std::string rname,rn,rt;

	std::getline(iss,rname,';');
	std::getline(iss,rn,';');
	std::getline(iss,rt,';');

	std::shared_ptr<Resistor> returnptr= std::shared_ptr<ResistorPart>(new ResistorPart(rname,std::stof(rn),std::stof(rt)));
	return returnptr;

}
