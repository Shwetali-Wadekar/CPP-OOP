/*
 * ReservationManager.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef RESERVATIONMANAGER_H_
#define RESERVATIONMANAGER_H_


#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Room.h"
#include "Reservation.h"

/**
 * Manages reservations and rooms in the system.
 */
class ReservationManager {
private:
    std::map<std::string, std::shared_ptr<Room>> rooms; // Key: Room number, Value: Room pointer
    std::map<std::string, std::shared_ptr<Reservation>> reservations; // Key: Reservation ID, Value: Reservation pointer

public:
    /**
     * Adds a room to the reservation system.
     *
     * @param room A smart pointer to the room being added.
     */
    void addRoom(const std::shared_ptr<Room>& room);

    /**
     * Adds a reservation to the system.
     *
     * @param reservation A smart pointer to the reservation being added.
     */
    void addReservation(const std::shared_ptr<Reservation>& reservation);

    /**
     * Books a room for a guest if available.
     *
     * @param reservationId The ID of the reservation.
     * @param roomNumber The room number to be booked.
     * @param guestName The name of the guest making the reservation.
     */
    void bookRoom(const std::string& reservationId, const std::string& roomNumber, const std::string& guestName);

    /**
     * Cancels a reservation and releases the room.
     *
     * @param reservationId The ID of the reservation to be canceled.
     */
    void cancelReservation(const std::string& reservationId);

    /**
     * Lists all rooms and their availability status.
     */
    void listRooms() const;

    /**
     * Lists all reservations.
     */
    void listReservations() const;
};

#endif /* RESERVATIONMANAGER_H_ */
