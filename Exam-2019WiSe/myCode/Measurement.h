/*
 * Measurement.h
 *
 *  Created on: 21 Jul 2024
 *      Author: hp
 */

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_
#include<cstdint>
#include<string>

class Measurement
{
	uint16_t timestamp;
public:
	Measurement(uint16_t timestamp);
	long getTimestamp() const;
	static uint16_t toTimestamp(int hour, int minute);
	static std::string toTimeOfDay(uint16_t timestamp);
	virtual std::string toString() const=0;
	static void parseLine(const std::string& line,uint16_t& timestamp, std::string& type, std::string& remainder );
	virtual ~Measurement();
};

std::ostream& operator<<(std::ostream& lhs, Measurement& rhs);

#endif /* MEASUREMENT_H_ */
