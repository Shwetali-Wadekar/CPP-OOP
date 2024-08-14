/*
 * Room.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Room.h"

Room::Room(const std::string &number) : roomNumber(number)
{
	this->isAvailable=1;
}

std::string Room::getRoomNumber() const
{
	return this->roomNumber;
}

bool Room::isRoomAvailable() const
{
	return this->isAvailable;
}

Room::~Room()
{
}
