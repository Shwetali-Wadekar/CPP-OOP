/*
 * ExceptionHandling.cpp
 *
 *  Created on: Jul 29, 2024
 *      Author: pradh
 */

#include "ExceptionHandling.h"

OrderProcessingException::OrderProcessingException(const std::string &message) : std::runtime_error(message)
{
}
//ExceptionHandling::ExceptionHandling()
//{
//	// TODO Auto-generated constructor stub
//
//}
//
//ExceptionHandling::~ExceptionHandling()
//{
//	// TODO Auto-generated destructor stub
//}
//
