/*
 * EventSystem.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "EventSystem.h"
#include<iostream>
void EventSystem::addEvent(std::unique_ptr<Event> event)
{
	eventManager.addEvent(std::move(event));
}

void EventSystem::registerAttendee(const std::string &name)
{
	std::shared_ptr<Attendee> attendee(new Attendee(name));
	attendees.insert(std::make_pair(name,attendee));
}

void EventSystem::unregisterAttendee(const std::string &name)
{
	auto found=attendees.find(name);
	if(found != attendees.end()) {
		attendees.erase(found);
	}else {
		throw std::invalid_argument(" attendee not exist");
	}

}

void EventSystem::attendeeRegisterForEvent(const std::string &attendeeName,
		const std::string &eventTitle)
{
	auto found=attendees.find(attendeeName);
	if(found != attendees.end()) {

		found->second->registerEvent(eventTitle);
	}else {
		throw std::invalid_argument(" attendee not exist");

	}

}

void EventSystem::attendeeUnregisterFromEvent(const std::string &attendeeName,
		const std::string &eventTitle)
{
	auto found=attendees.find(attendeeName);
	if(found != attendees.end()) {

		found->second->unregisterEvent(eventTitle);
	}else {
		throw std::invalid_argument(" attendee not exist");

	}

}

void EventSystem::listAttendeesForEvent(const std::string &eventTitle) const
{

	//eventManager.getEvent(eventTitle)
	for(auto iter = attendees.begin() ; iter != attendees.end() ; ++iter ) {

		if((*iter).second->isRegistered(eventTitle)) {
		//	std::couz
			std::cout<<(*iter).first<<std::endl;
		}

	}

}

void EventSystem::displayAllEvents() const
{
	eventManager.listEvents();
}

void EventSystem::displayAttendeeDetails(const std::string &attendeeName) const
{
	for(auto iter = attendees.begin() ; iter != attendees.end() ; ++iter ) {
		std::cout<<"Name: "<<(*iter).first<<std::endl;
		std::cout<<"registered events: "<<std::endl;
		(*iter).second->listRegisteredEvents();
	}

}

void EventSystem::searchEventsByKeyword(const std::string &keyword) const
{
	eventManager.listEventsByKeyword(keyword);
}
