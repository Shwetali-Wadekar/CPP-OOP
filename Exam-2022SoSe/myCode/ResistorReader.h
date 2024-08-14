/*
 * ResistorReader.h
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#ifndef RESISTORREADER_H_
#define RESISTORREADER_H_
#include "Resistor.h"
#include<map>

class ResistorReader
{
public:
	ResistorReader();
	static void read(std::istream& in, std::map<std::string, Resistor::ResistorPtr>& found);
};

#endif /* RESISTORREADER_H_ */
