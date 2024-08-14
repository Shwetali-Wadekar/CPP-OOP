/*
 * SerialResistorConnection.h
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#ifndef SERIALRESISTORCONNECTION_H_
#define SERIALRESISTORCONNECTION_H_

#include "ResistorConnection.h"

class SerialResistorConnection: public ResistorConnection
{
public:
	SerialResistorConnection(std::string name);
	virtual char separator() const override;

	 float nominalValue() const;
	 float maximumValue() const;
	 float minimumValue() const;
};

#endif /* SERIALRESISTORCONNECTION_H_ */
