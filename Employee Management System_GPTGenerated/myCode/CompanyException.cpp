/*
 * CompanyException.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "CompanyException.h"

CompanyException::CompanyException(const std::string &message): std::runtime_error(message)
{
}
