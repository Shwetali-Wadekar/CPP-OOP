/*
 * Reservation.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Reservation.h"

Reservation::Reservation(const std::string& reservationId,
		const std::shared_ptr<Room>& room, const std::string& guestName) :
		reservationId(reservationId) , room(room) , guestName(guestName)

{
	room->bookRoom();
}

std::string Reservation::getReservationId() const
{
	return this->reservationId;
}

std::shared_ptr<Room> Reservation::getRoom() const
{
	return this->room;
}

std::string Reservation::getGuestName() const
{
	return this->guestName;
}

void Reservation::cancelReservation()
{
	room->releaseRoom();

}
