/*
 * EventSystem.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef EVENTSYSTEM_H_
#define EVENTSYSTEM_H_


#include "EventManager.h"
#include "Attendee.h"
#include <memory>
#include <map>

/**
 * Manages the overall event and attendee system.
 * Provides methods for interacting with both events and attendees.
 */
class EventSystem {
private:
    EventManager eventManager;
    std::map<std::string, std::shared_ptr<Attendee>> attendees;

public:
    /**
     * Adds an event to the system.
     *
     * @param event A unique pointer to the event to add.
     */
    void addEvent(std::unique_ptr<Event> event);

    /**
     * Registers an attendee with the system.
     *
     * @param name The name of the attendee.
     */
    void registerAttendee(const std::string& name);

    /**
     * Unregisters an attendee from the system.
     *
     * @param name The name of the attendee.
     */
    void unregisterAttendee(const std::string& name);

    /**
     * Allows an attendee to register for an event.
     *
     * @param attendeeName The name of the attendee.
     * @param eventTitle The title of the event.
     */
    void attendeeRegisterForEvent(const std::string& attendeeName, const std::string& eventTitle);

    /**
     * Allows an attendee to unregister from an event.
     *
     * @param attendeeName The name of the attendee.
     * @param eventTitle The title of the event.
     */
    void attendeeUnregisterFromEvent(const std::string& attendeeName, const std::string& eventTitle);

    /**
     * Lists all attendees registered for a specific event.
     *
     * @param eventTitle The title of the event.
     */
    void listAttendeesForEvent(const std::string& eventTitle) const;

    /**
     * Displays details of all events.
     */
    void displayAllEvents() const;

    /**
     * Displays details of a specific attendee.
     *
     * @param attendeeName The name of the attendee.
     */
    void displayAttendeeDetails(const std::string& attendeeName) const;

    /**
     * Searches for events containing a keyword in their description.
     *
     * @param keyword The keyword to search for.
     */
    void searchEventsByKeyword(const std::string& keyword) const;
};

#endif /* EVENTSYSTEM_H_ */
