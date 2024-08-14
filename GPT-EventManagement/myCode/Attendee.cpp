/*
 * Attendee.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Attendee.h"
#include <stdexcept>
#include<iostream>
Attendee::Attendee(const std::string &name) : name(name)
{
}

void Attendee::registerEvent(const std::string &eventTitle)
{
	registeredEvents.insert(eventTitle);
}

void Attendee::registerEvent(const std::set<std::string> &eventTitles)
{

	for(auto iter = eventTitles.begin() ; iter != eventTitles.end() ; ++iter) {

		registeredEvents.insert(*iter);
	}
}

void Attendee::unregisterEvent(const std::string &eventTitle)
{
	auto found= registeredEvents.find(eventTitle);

	if( found != registeredEvents.end()) {
		registeredEvents.erase(eventTitle);
	}else {
		throw std::invalid_argument("attendee does not registered with this event");
	}
}

bool Attendee::isRegistered(const std::string &eventTitle) const
{
	auto found= registeredEvents.find(eventTitle);
	if( found != registeredEvents.end()) {
		return 1;
	}
	return 0;

}

void Attendee::listRegisteredEvents() const
{
	for(auto iter = registeredEvents.begin() ; iter != registeredEvents.end() ; ++iter) {

		std::cout<<(*iter)<<std::endl;

	}

}

std::string Attendee::getName() const
{
	return name;
}
