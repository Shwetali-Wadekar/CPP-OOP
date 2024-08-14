/*
 * Measurement.cpp
 *
 *  Created on: 21 Jul 2024
 *      Author: hp
 */

#include "Measurement.h"
#include <stdexcept>
#include<iomanip>
#include<sstream>
using namespace std;

Measurement::Measurement(uint16_t timestamp) : timestamp(timestamp)
{
	// TODO Auto-generated constructor stub

}

long Measurement::getTimestamp() const
{
	return timestamp;
}

uint16_t Measurement::toTimestamp(int hour, int minute)
{
	long timemeasurement=0;
	if(hour >= 0 && hour <=24 && minute >=0 && minute <=60) {

		timemeasurement= hour*60+minute;

	}else {
		throw std::invalid_argument("hour/minute invalid argument!");
	}
	return timemeasurement;
}

std::string Measurement::toTimeOfDay(uint16_t timestamp)
{
	int hour=timestamp/60;
	int min= timestamp%60;

	std::ostringstream oss;
	oss<<setw(2)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<min;
	return oss.str();
}

Measurement::~Measurement()
{
	// TODO Auto-generated destructor stub
}

std::ostream& operator <<(std::ostream &lhs, Measurement &rhs)
{
	lhs<<rhs.toTimeOfDay(rhs.getTimestamp())<<" "<<rhs.toString();
	return lhs;
}
//480;Humidity:
void Measurement::parseLine(const std::string &line, uint16_t &timestamp,
		std::string &type, std::string &remainder)
{
	std::istringstream iss(line);
	std::string timestampstring;
	std::getline(iss,timestampstring,';');
	std::getline(iss,type,':');
	std::getline(iss,remainder);
	//timestamp=std::static_cast<uint16_t>(timestampstring);//std::stol(timestampstring);
	timestamp=std::stoul(timestampstring);



}
