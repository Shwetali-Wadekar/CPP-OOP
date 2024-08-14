/*
 * SuiteRoom.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef SUITEROOM_H_
#define SUITEROOM_H_


#include "Room.h"

/**
 * Represents a suite room in the reservation system.
 */
class SuiteRoom : public Room {
private:
    int additionalCharges;  // Additional charges for the suite room.

public:
    /**
     * Constructor for the SuiteRoom class.
     *
     * @param number The room number to initialize the suite room with.
     * @param charges The additional charges for the suite room.
     */
    SuiteRoom(const std::string& number, int charges);

    /**
     * Marks the suite room as booked.
     * Implementation should set isAvailable to false.
     */
    void bookRoom() override;

    /**
     * Marks the suite room as available.
     * Implementation should set isAvailable to true.
     */
    void releaseRoom() override;

    /**
     * Gets the additional charges for the suite room.
     *
     * @return The additional charges as an integer.
     */
    int getAdditionalCharges() const;
};

#endif /* SUITEROOM_H_ */
