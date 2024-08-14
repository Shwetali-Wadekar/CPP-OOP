/*
 * ResistorPart.h
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#ifndef RESISTORPART_H_
#define RESISTORPART_H_

#include "Resistor.h"

class ResistorPart: public Resistor
{
	float value;
	float tolerance;

public:
	ResistorPart(std::string name, float value,float tolerance);
	 float nominalValue() const;
	 float maximumValue() const;
	 float minimumValue() const;
	void write(std::ostream& out);
	static ResistorPtr from(std::string line);

};

#endif /* RESISTORPART_H_ */
