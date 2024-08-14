/*
 * DuplicateBookException.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "DuplicateBookException.h"

DuplicateBookException::DuplicateBookException(const std::string &isbn) : std::invalid_argument("book with the same ISBN ("+isbn+") already exists")
{
}
