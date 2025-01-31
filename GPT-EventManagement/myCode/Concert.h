/*
 * Concert.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef CONCERT_H_
#define CONCERT_H_


#include "Event.h"

/**
 * Derived class representing a concert event.
 * This class provides additional details specific to concerts.
 */
class Concert : public Event {
private:
    std::string bandName;
    std::string venue;

public:
    /**
     * Constructor for Concert.
     *
     * @param title The title of the concert.
     * @param description The description of the concert.
     * @param bandName The name of the band performing.
     * @param venue The venue of the concert.
     */
    Concert(const std::string& title, const std::string& description,
            const std::string& bandName, const std::string& venue);

    /**
     * Displays details of the concert event.
     */
    virtual void display() const override;

    /**
     * Overloaded display method for the concert event.
     *
     * @param format The format to display the event details (e.g., "short", "full").
     */
    virtual void display(const std::string& format) const override;

    /**
     * Gets the name of the band.
     *
     * @return The name of the band.
     */
    std::string getBandName() const;

    /**
     * Gets the venue of the concert.
     *
     * @return The venue of the concert.
     */
    std::string getVenue() const;
};


#endif /* CONCERT_H_ */
