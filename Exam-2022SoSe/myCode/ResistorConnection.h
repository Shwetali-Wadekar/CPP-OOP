/*
 * ResistorConnection.h
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#ifndef RESISTORCONNECTION_H_
#define RESISTORCONNECTION_H_

#include "Resistor.h"
#include<list>
class ResistorConnection: public Resistor
{
protected:
	std::list<ResistorPtr> resistors;

public:
	ResistorConnection(std::string name);
	virtual char separator() const;
	std::string getName() const override;
	ResistorConnection& operator+= (const std::shared_ptr<Resistor>& resistor);
	void write(std::ostream& out) ;


};

#endif /* RESISTORCONNECTION_H_ */
