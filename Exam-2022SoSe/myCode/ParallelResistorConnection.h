/*
 * ParallelResistorConnection.h
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#ifndef PARALLELRESISTORCONNECTION_H_
#define PARALLELRESISTORCONNECTION_H_

#include "ResistorConnection.h"

class ParallelResistorConnection: public ResistorConnection
{
public:
	ParallelResistorConnection(std::string name);
	virtual char separator() const override;

	 float nominalValue() const;
	 float maximumValue() const;
	 float minimumValue() const;
};

#endif /* PARALLELRESISTORCONNECTION_H_ */
