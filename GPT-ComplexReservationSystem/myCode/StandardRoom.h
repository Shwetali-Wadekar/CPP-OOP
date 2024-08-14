/*
 * StandardRoom.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef STANDARDROOM_H_
#define STANDARDROOM_H_


#include "Room.h"

/**
 * Represents a standard room in the reservation system.
 */
class StandardRoom : public Room {
public:
    /**
     * Constructor for the StandardRoom class.
     *
     * @param number The room number to initialize the standard room with.
     */
    StandardRoom(const std::string& number);

    /**
     * Marks the standard room as booked.
     * Implementation should set isAvailable to false.
     */
    void bookRoom() override;

    /**
     * Marks the standard room as available.
     * Implementation should set isAvailable to true.
     */
    void releaseRoom() override;
};


#endif /* STANDARDROOM_H_ */
