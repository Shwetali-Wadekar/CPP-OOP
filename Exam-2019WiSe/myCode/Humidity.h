/*
 * Humidity.h
 *
 *  Created on: 21 Jul 2024
 *      Author: hp
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_
#include<memory>

#include "Measurement.h"

class Humidity: public Measurement
{
	float humidity;
public:
	Humidity(uint16_t timestamp, float humidity);
	float getHumidity() const;
	std::string toString() const;
	static std::shared_ptr<Humidity>fromString(uint16_t timestamp , std::string value );
	static Humidity* toType(Measurement* ptr);
};

#endif /* HUMIDITY_H_ */
