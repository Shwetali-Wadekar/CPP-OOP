/*
 * EnergyConsumption.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "EnergyConsumption.h"

EnergyConsumption::EnergyConsumption(std::string applianceId,
		Poco::DateTime startTime, Poco::DateTime endTime) : applianceId(applianceId) , startTime(startTime) , endTime(endTime)
{
}

std::string EnergyConsumption::getApplianceId() const
{
	return applianceId;
}

double EnergyConsumption::getDuration() const
{
	auto duration= endTime-startTime;
	return duration.totalHours();
}
