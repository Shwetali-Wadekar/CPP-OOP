/*
 * Humidity.cpp
 *
 *  Created on: 21 Jul 2024
 *      Author: hp
 */

#include "Humidity.h"
#include<sstream>
Humidity::Humidity(uint16_t timestamp, float humidity) : Measurement(timestamp), humidity(humidity)
{
	// TODO Auto-generated constructor stub

}

float Humidity::getHumidity() const
{
	return humidity;
}

std::string Humidity::toString() const
{
	return "Humidity: "+std::to_string(humidity)+"%";
}

std::shared_ptr<Humidity> Humidity::fromString(uint16_t timestamp,
		std::string value)
{
	std::istringstream iss(value);
	std::string data;
	std::getline(iss,data,'%');
	return std::shared_ptr<Humidity>(new Humidity(timestamp,std::stof(data)));
}

Humidity* Humidity::toType(Measurement *ptr)
{
	Humidity* pTemp = dynamic_cast<Humidity*>(ptr);
	if (pTemp != nullptr) {
		return pTemp;

	}else {
		return nullptr;
	}
}
