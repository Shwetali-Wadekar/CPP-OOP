/*
 * Concert.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Concert.h"
#include<iostream>
using namespace std;
Concert::Concert(const std::string &title, const std::string &description,
		const std::string &bandName, const std::string &venue) :
		Event(title,description) , bandName(bandName) , venue(venue)
{
}

void Concert::display() const
{
	cout<<title+": "+description<<endl;

}

void Concert::display(const std::string &format) const
{
	if(format=="short") {
		Event::display(format);
	}else {
		Event::display(format);
		cout<<"Band Name: "<<bandName<<endl<<"Venue: "+venue<<endl;
	}
}

std::string Concert::getBandName() const
{
	return bandName;
}

std::string Concert::getVenue() const
{
	return venue;
}
