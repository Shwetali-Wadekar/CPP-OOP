/*
 * Attendee.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef ATTENDEE_H_
#define ATTENDEE_H_


#include <string>
#include <set>
#include <memory>

/**
 * Represents an attendee who can register for events.
 */
class Attendee {
private:
    std::string name;
    std::set<std::string> registeredEvents; // Event titles

public:
    /**
     * Constructor for Attendee.
     *
     * @param name The name of the attendee.
     */
    Attendee(const std::string& name);

    /**
     * Registers the attendee for an event.
     *
     * @param eventTitle The title of the event to register for.
     */
    void registerEvent(const std::string& eventTitle);

    /**
     * Overloaded method to register the attendee for multiple events.
     *
     * @param eventTitles A set of event titles to register for.
     */
    void registerEvent(const std::set<std::string>& eventTitles);

    /**
     * Unregisters the attendee from an event.
     *
     * @param eventTitle The title of the event to unregister from.
     */
    void unregisterEvent(const std::string& eventTitle);

    /**
     * Checks if the attendee is registered for an event.
     *
     * @param eventTitle The title of the event to check.
     * @return True if the attendee is registered, false otherwise.
     */
    bool isRegistered(const std::string& eventTitle) const;

    /**
     * Lists all registered events.
     */
    void listRegisteredEvents() const;

    /**
     * Gets the name of the attendee.
     *
     * @return The name of the attendee.
     */
    std::string getName() const;
};

#endif /* ATTENDEE_H_ */
