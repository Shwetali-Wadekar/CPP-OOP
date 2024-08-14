/*
 * Employee.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "Employee.h"

Employee::Employee(std::string name, int id, float salary) : name(name) ,id(id) , salary(salary)
{
}

std::string Employee::getName() const
{
	return name;
}

int Employee::getId() const
{
	return id;
}

float Employee::getSalary() const
{
	return salary;
}

void Employee::setSalary(float salary)
{
	this->salary=salary;

}
