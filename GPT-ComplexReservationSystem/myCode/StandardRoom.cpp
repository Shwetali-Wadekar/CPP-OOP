/*
 * StandardRoom.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "StandardRoom.h"

StandardRoom::StandardRoom(const std::string &number) : Room(number)
{
}

void StandardRoom::bookRoom()
{
	this->isAvailable=0;
}

void StandardRoom::releaseRoom()
{
	this->isAvailable=1;
}
