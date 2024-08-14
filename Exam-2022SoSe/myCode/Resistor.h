/*
 * Resistor.h
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#ifndef RESISTOR_H_
#define RESISTOR_H_
#include<string>
#include <memory>

class Resistor
{
	std::string name;
public:
	Resistor(std::string name);
	virtual std::string getName() const;
	virtual float nominalValue() const=0;
	virtual float maximumValue() const=0;
	virtual float minimumValue() const=0;
	 std::string toString() const;
	virtual ~Resistor();
	typedef std::shared_ptr<Resistor> ResistorPtr;
	virtual void write(std::ostream& out);
};

std::ostream& operator<<(std::ostream& lhs, Resistor& rhs);

#endif /* RESISTOR_H_ */
