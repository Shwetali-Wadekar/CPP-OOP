/*
 * ReservationManager.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "ReservationManager.h"
#include <stdexcept>
#include<iostream>
//   std::map<std::string, std::shared_ptr<Room>> rooms; // Key: Room number, Value: Room pointer
 //   std::map<std::string, std::shared_ptr<Reservation>> reservations; // Key: Reservation ID, Value: Reservation pointer
using namespace std;
void ReservationManager::addRoom(const std::shared_ptr<Room> &room)
{
	rooms.insert(make_pair(room->getRoomNumber(),room));
}

void ReservationManager::addReservation(
		const std::shared_ptr<Reservation> &reservation)
{
	reservations.insert(make_pair(reservation->getReservationId(),reservation));
}

void ReservationManager::bookRoom(const std::string &reservationId,
		const std::string &roomNumber, const std::string &guestName)
{
	auto found=rooms.find(roomNumber);

	if(found != rooms.end()) {
		if(found->second->isRoomAvailable()) {
			shared_ptr<Reservation> reservation(new Reservation(reservationId,found->second,guestName));
			addReservation(reservation);
		}else {
			throw std::invalid_argument("room is already booked!");
		}
	}else {
		throw invalid_argument("room does not exists");
	}
}

void ReservationManager::cancelReservation(const std::string &reservationId)
{
	auto found= reservations.find(reservationId);

	if(found != reservations.end()) {
		found->second->cancelReservation();
		reservations.erase(found);
	}else {
		throw invalid_argument("reservation does not exist");
	}
}

void ReservationManager::listRooms() const
{
	for(auto iter=rooms.begin() ; iter != rooms.end() ; ++iter) {
		cout<<iter->first<<": "<<iter->second->isRoomAvailable()<<endl;
	}
}

void ReservationManager::listReservations() const
{
	for(auto iter=reservations.begin() ; iter != reservations.end() ; ++iter) {
	cout<<iter->first<<": "<<iter->second->getGuestName()<<", Booked Room: "<<iter->second->getRoom()->getRoomNumber()<<endl;
}
}
