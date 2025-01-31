/*
 * Conference.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Conference.h"
#include <iostream>

using namespace std;
Conference::Conference(const std::string &title, const std::string &description,
		const std::vector<std::string> &speakers, const std::string &location) :
		Event(title,description) , speakers(speakers) , location(location)
{
}

void Conference::display() const
{
	cout<<title+": "+description<<endl;
}

void Conference::display(const std::string &format) const
{
	if(format=="short") {
		Event::display(format);
	}else {
		Event::display(format);
		cout<<"location: "<<location<<endl;
		cout<<"speakers: ";
		cout<<getSpeakersAsString();
		cout<<endl;
	}
}


std::string Conference::getSpeakersAsString() const
{
	std::string speakersStr;
	for(auto i= speakers.begin() ; i != speakers.end() ; ++i) {
		speakersStr=speakersStr+(*i)+", ";
	}
	return speakersStr;
}

std::string Conference::getLocation() const
{
	return location;
}
