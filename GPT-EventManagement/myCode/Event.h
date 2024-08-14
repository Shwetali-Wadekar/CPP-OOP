/*
 * Event.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef EVENT_H_
#define EVENT_H_


#include <string>
#include <memory>
#include <sstream>

/**
 * Base class representing a generic event.
 * This class provides the basic structure for events and defines
 * a pure virtual method for displaying event details.
 */
class Event {
protected:
    std::string title;
    std::string description;

public:
    /**
     * Constructor for Event.
     *
     * @param title The title of the event.
     * @param description The description of the event.
     */
    Event(const std::string& title, const std::string& description);

    virtual ~Event() = default;

    /**
     * Gets the title of the event.
     *
     * @return The title of the event.
     */
    virtual std::string getTitle() const;

    /**
     * Gets the description of the event.
     *
     * @return The description of the event.
     */
    virtual std::string getDescription() const;

    /**
     * Displays details of the event. Must be implemented by derived classes.
     */
    virtual void display() const = 0; // Pure virtual method

    /**
     * Displays details of the event with a specific format.
     * This is an overloaded method for different display formats.
     *
     * @param format A string representing the format (e.g., "short", "detailed").
     */
    virtual void display(const std::string& format) const;

    /**
     * Formats the event details into a string.
     *
     * @param format The format to use (e.g., "short", "full").
     * @return A formatted string representation of the event.
     */
    std::string formatDetails(const std::string& format) const;
};

#endif /* EVENT_H_ */
