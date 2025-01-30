
#include "HealthcareException.h"

HealthcareException::HealthcareException(const std::string &message) : std::runtime_error(message)
{
}
