#include "TV.h"
#include "DeviceException.h"
#include <stdexcept>
TV::TV(const std::string &id, const std::string &name, int volume) : Device(id,name) , volume(volume)
{
}

void TV::setVolume(int level)
{
	if(level<=100) {
	this->volume= level; }
	else {
		throw DeviceException("volume not more then 100");

	}
}

int TV::getVolume() const
{
	return this->volume;
}

void TV::turnOn()
{
	this->status=1;
}

void TV::turnOff()
{
	this->status=0;
}

bool TV::getStatus() const
{
	return this->status;
}
