/*
 * HealthcareException.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "HealthcareException.h"

HealthcareException::HealthcareException(const std::string &message) : std::runtime_error(message)
{
}
