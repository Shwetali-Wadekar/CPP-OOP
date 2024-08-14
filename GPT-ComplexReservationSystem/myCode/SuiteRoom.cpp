/*
 * SuiteRoom.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "SuiteRoom.h"

SuiteRoom::SuiteRoom(const std::string &number, int charges) :Room(number) , additionalCharges(charges)
{
}

void SuiteRoom::bookRoom()
{
	this->isAvailable=0;
}

void SuiteRoom::releaseRoom()
{
	this->isAvailable=1;
}

int SuiteRoom::getAdditionalCharges() const
{
	return this->additionalCharges;
}
