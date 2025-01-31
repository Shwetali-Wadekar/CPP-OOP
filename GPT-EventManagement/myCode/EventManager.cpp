/*
 * EventManager.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "EventManager.h"
#include<iostream>
#include<string>
void EventManager::addEvent(std::unique_ptr<Event> event)
{
	events.insert(std::make_pair(event->getTitle(),std::move(event)));
}

std::shared_ptr<Event> EventManager::getEvent(const std::string &title) const
{
	auto foundEvent=events.find(title);
	 if(foundEvent!= events.end()) {
		 return std::shared_ptr<Event>(foundEvent->second.get());
	 }
	 return nullptr;

}

void EventManager::removeEvent(const std::string &title)
{
	auto foundEvent=events.find(title);
	 if(foundEvent!= events.end()) {

		 events.erase(foundEvent);
	 }else {
		 throw std::invalid_argument ("event does not exist!");
	 }

}

void EventManager::listEvents() const
{
	for(auto iter = events.begin() ; iter != events.end() ; ++iter) {

		std::cout<<(*iter).first<<std::endl;

	}
}

void EventManager::listEvents(const std::string &description) const
{
	for(auto iter = events.begin() ; iter != events.end() ; ++iter) {

		(*iter).second->display(description);
	}

}

void EventManager::listEventsByKeyword(const std::string &keyword) const
{

	for(auto iter = events.begin() ; iter != events.end() ; ++iter) {
		std::string title= (*iter).first;
		if(title.find(keyword) != std::string::npos) {
			std::cout<<title<<std::endl;
		}

	}


}
