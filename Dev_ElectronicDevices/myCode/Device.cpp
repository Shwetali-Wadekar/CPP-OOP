#include "Device.h"

Device::Device(const std::string &id, const std::string &name) : id(id) , name(name)
{
	status=0;
}

Device::~Device()
{
}

std::string Device::getId() const
{
	return this->id;
}

std::string Device::getName() const
{
	return this->name;
}
