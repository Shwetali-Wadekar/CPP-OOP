/*
 * Room.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef ROOM_H_
#define ROOM_H_


#include <string>

/**
 * Abstract base class for all room types.
 */
class Room {
protected:
    std::string roomNumber;  // The unique identifier for the room.
    bool isAvailable;        // Availability status of the room.

public:
    /**
     * Constructor for the Room class.
     *
     * @param number The room number to initialize the room with.
     */
    Room(const std::string& number);

    /**
     * Gets the room number.
     *
     * @return The room number as a string.
     */
    std::string getRoomNumber() const;

    /**
     * Checks if the room is available.
     *
     * @return True if the room is available, false otherwise.
     */
    bool isRoomAvailable() const;

    /**
     * Marks the room as booked.
     * This method should set isAvailable to false.
     */
    virtual void bookRoom() = 0;

    /**
     * Marks the room as available.
     * This method should set isAvailable to true.
     */
    virtual void releaseRoom() = 0;

    virtual ~Room();
};


#endif /* ROOM_H_ */
