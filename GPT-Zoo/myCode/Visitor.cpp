/*
 * Visitor.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Visitor.h"

Visitor::Visitor(std::string name, int age) : name(name) , age(age)
{
}

std::string Visitor::getName() const
{
	return name;
}

int Visitor::getAge() const
{
	return age;
}

void Visitor::visitZoo(const std::string &zooName)
{
	this->visitedZoos.insert(zooName);
}

std::set<std::string> Visitor::getVisitedZoos() const
{
	return this->visitedZoos;
}

bool Visitor::hasVisitedZoo(const std::string &zooName) const
{
	if(visitedZoos.find(zooName) != visitedZoos.end() ){
		return true;
	}
	return false;
}
