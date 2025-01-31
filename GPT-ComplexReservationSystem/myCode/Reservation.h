/*
 * Reservation.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef RESERVATION_H_
#define RESERVATION_H_


#include <memory>
#include <string>
#include "Room.h"

/**
 * Represents a reservation in the system.
 */
class Reservation {
private:
    std::string reservationId;    // Unique identifier for the reservation.
    std::shared_ptr<Room> room;   // The room associated with the reservation.
    std::string guestName;        // Name of the guest who made the reservation.

public:
    /**
     * Constructor for the Reservation class.
     *
     * @param id The unique ID for the reservation.
     * @param room A smart pointer to the room being reserved.
     * @param guest The name of the guest making the reservation.
     */
    Reservation(const std::string& reservationId, const std::shared_ptr<Room>& room, const std::string& guestName);

    /**
     * Gets the reservation ID.
     *
     * @return The reservation ID as a string.
     */
    std::string getReservationId() const;

    /**
     * Gets the room associated with the reservation.
     *
     * @return A smart pointer to the room.
     */
    std::shared_ptr<Room> getRoom() const;

    /**
     * Gets the name of the guest who made the reservation.
     *
     * @return The guest's name as a string.
     */
    std::string getGuestName() const;

    /**
     * Cancels the reservation.
     * This method should release the room associated with the reservation.
     */
    void cancelReservation();
};


#endif /* RESERVATION_H_ */
