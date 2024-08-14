/*
 * Patient.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "Patient.h"

Patient::Patient(const std::string &name, const std::string &patientId, int age) :
name(name) , patientId(patientId) , age(age)
{
}

std::string Patient::getName() const
{
	return this->name;
}

std::string Patient::getPatientId() const
{
	return this->patientId;
}

int Patient::getAge() const
{
	return this->age;
}

void Patient::setAge(int age)
{
	this->age=age;
}
