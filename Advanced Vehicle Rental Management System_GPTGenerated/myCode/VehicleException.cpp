/*
 * VehicleException.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "VehicleException.h"

    VehicleException::VehicleException(const std::string& message) : std::runtime_error(message) {}
