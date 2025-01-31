
#include "DeviceException.h"

DeviceException::DeviceException(const std::string &message) : message(message)
{
}

const char* DeviceException::what() const noexcept
{
	return message.c_str();
}
