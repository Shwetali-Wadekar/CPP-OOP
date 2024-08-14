/*
 * Conference.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef CONFERENCE_H_
#define CONFERENCE_H_


#include "Event.h"
#include <vector>

/**
 * Derived class representing a conference event.
 * This class provides additional details specific to conferences.
 */
class Conference : public Event {
private:
    std::vector<std::string> speakers;
    std::string location;

public:
    /**
     * Constructor for Conference.
     *
     * @param title The title of the conference.
     * @param description The description of the conference.
     * @param speakers A list of speakers at the conference.
     * @param location The location of the conference.
     */
    Conference(const std::string& title, const std::string& description,
               const std::vector<std::string>& speakers, const std::string& location);

    /**
     * Displays details of the conference event.
     */
    virtual void display() const override;

    /**
     * Overloaded display method for the conference event.
     *
     * @param format The format to display the event details (e.g., "short", "detailed").
     */
    virtual void display(const std::string& format) const override;

    /**
     * Gets the list of speakers as a comma-separated string.
     *
     * @return A comma-separated string of speaker names.
     */
    std::string getSpeakersAsString() const;

    /**
     * Gets the location of the conference.
     *
     * @return The location of the conference.
     */
    std::string getLocation() const;
};

#endif /* CONFERENCE_H_ */
