
#include "Speaker.h"
#include "DeviceException.h"
Speaker::Speaker(const std::string &id, const std::string &name, int volume) : Device(id,name) , volume(volume)
{
}

void Speaker::setVolume(int level)
{
	if(level<=100) {
		this->volume= level; }
	else {
		throw DeviceException("volume not more then 100");
	}
}
int Speaker::getVolume() const
{
	return this->volume;
}

void Speaker::turnOn()
{
	this->status=1;
}

void Speaker::turnOff()
{
	this->status=0;
}

bool Speaker::getStatus() const
{
	return this->status;
}
