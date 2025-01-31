/*
 * Temperature.h
 *
 *  Created on: 21 Jul 2024
 *      Author: hp
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_
#include<memory>
#include "Measurement.h"

class Temperature: public Measurement
{
	float temperature;
public:
	Temperature(uint16_t timestamp, float temperature);
	float getTemperature() const;
	std::string toString() const;
	static std::shared_ptr<Temperature>fromString(uint16_t timestamp , std::string value );
	static Temperature* toType(Measurement* ptr);
};

#endif /* TEMPERATURE_H_ */
