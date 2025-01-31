
#include "DeviceFactory.h"
#include <iomanip>
#include <sstream>
int  DeviceFactory::idCounter;
std::string DeviceFactory::generateId()
{
	std::ostringstream oss;
	oss<<"DE"<<std::setw(8)<<std::setfill('0')<<idCounter;
	idCounter++;
	return oss.str();
	return " ";
}

std::unique_ptr<TV> DeviceFactory::createTV(const std::string &name, int volume)
{
	std::unique_ptr<TV> tv(new TV(generateId(),name,volume));
	return tv;
}

std::unique_ptr<Speaker> DeviceFactory::createSpeaker(const std::string &name,
		int volume)
{
	std::unique_ptr<Speaker> speaker(new Speaker(generateId(),name,volume));
	return speaker;
}
