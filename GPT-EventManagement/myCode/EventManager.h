/*
 * EventManager.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_


#include <map>
#include <memory>
#include "Event.h"

/**
 * Manages a collection of events.
 * Provides methods to add, retrieve, remove, and list events.
 */
class EventManager {
private:
    std::map<std::string, std::unique_ptr<Event>> events;

public:
    /**
     * Adds an event to the manager.
     *
     * @param event A unique pointer to the event to add.
     */
    void addEvent(std::unique_ptr<Event> event);

    /**
     * Retrieves an event by title.
     *
     * @param title The title of the event to retrieve.
     * @return A shared pointer to the event, or nullptr if not found.
     */
    std::shared_ptr<Event> getEvent(const std::string& title) const;

    /**
     * Removes an event by title.
     *
     * @param title The title of the event to remove.
     */
    void removeEvent(const std::string& title);

    /**
     * Lists all events.
     */
    void listEvents() const;

    /**
     * Lists all events with a specific description.
     * Demonstrates method overloading.
     *
     * @param description The description to filter events by.
     */
    void listEvents(const std::string& description) const;

    /**
     * Lists all events with titles containing a specific keyword.
     * Demonstrates string search and filtering.
     *
     * @param keyword The keyword to search for in event titles.
     */
    void listEventsByKeyword(const std::string& keyword) const;
};

#endif /* EVENTMANAGER_H_ */
