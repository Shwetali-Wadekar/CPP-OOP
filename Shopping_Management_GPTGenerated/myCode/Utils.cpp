/*
 * Utils.cpp
 *
 *  Created on: Jul 29, 2024
 *      Author: pradh
 */

#include "Utils.h"
#include <iostream>
#include <stdexcept>
#include <boost/lexical_cast.hpp>

std::string Utils::toUpperCase(const std::string &str)
{
	std::string uppercaseStr="";
	for( size_t i = 0 ; i < str.size() ; ++i) {
		uppercaseStr.push_back(std::toupper(str[i]));
	}
	return uppercaseStr;
}

bool Utils::isValidFloat(const std::string &str)
{
	try {
		size_t pos;
		std::stof(str, &pos);
		return pos == str.size();
	} catch (std::exception& e) {
		return false;
	}
}
