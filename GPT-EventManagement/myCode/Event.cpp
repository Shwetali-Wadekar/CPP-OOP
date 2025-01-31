/*
 * Event.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Event.h"
#include <iostream>
#include <sstream>

using namespace std;
Event::Event(const std::string &title, const std::string &description) : title(title) , description(description)
{
}

std::string Event::getTitle() const
{
	return title;
}

std::string Event::getDescription() const
{
	return description;
}

void Event::display(const std::string &format) const
{
	if(format=="short") {
		std::cout<<"Title: "<<title<<endl;
	}
		std::cout<<"Title: "<<title<<endl<<"Description: "+description<<endl;

	//retur
}

std::string Event::formatDetails(const std::string &format) const
{
	if(format=="short") {
		return title;
	}
		return title+","+description;
}
