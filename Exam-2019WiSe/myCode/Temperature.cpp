/*
 * Temperature.cpp
 *
 *  Created on: 21 Jul 2024
 *      Author: hp
 */

#include "Temperature.h"
#include<sstream>
Temperature::Temperature(uint16_t timestamp, float temperature) : Measurement(timestamp), temperature(temperature)
{
	// TODO Auto-generated constructor stub

}

float Temperature::getTemperature() const
{
	return temperature;
}

std::string Temperature::toString() const
{
	return "Temperature: "+std::to_string(temperature)+"°C";
}

std::shared_ptr<Temperature> Temperature::fromString(uint16_t timestamp,
		std::string value)
{
	std::istringstream iss(value);
	std::string data;
	std::getline(iss,data,'°');
	return std::shared_ptr<Temperature>(new Temperature(timestamp,std::stof(data)));
}

Temperature* Temperature::toType(Measurement *ptr)
{
	Temperature* pTemp = dynamic_cast<Temperature*>(ptr);
	if (pTemp != nullptr) {
		return pTemp;

	}else {
		return nullptr;
	}
}
