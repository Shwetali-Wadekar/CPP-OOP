/*
 * Employee.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "Employee.h"

Employee::Employee(const std::string &name, const std::string &id, float salary) : name(name) ,  id(id) , salary(salary)
{
}

std::string Employee::getName() const
{
	return this->name;
}

std::string Employee::getId() const
{
	return this->id;
}

float Employee::getSalary() const
{
	return this->salary;
}

void Employee::setSalary(float salary)
{
	this->salary=salary;
}
