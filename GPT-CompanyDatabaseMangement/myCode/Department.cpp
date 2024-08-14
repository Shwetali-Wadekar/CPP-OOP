/*
 * Department.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "Department.h"
#include "Employee.h"

Department::Department(std::string name) : name(name)
{
}

void Department::addEmployee(std::shared_ptr<Employee> employee)
{
	employees.push_back(employee);
}

float Department::totalSalary() const
{
	float team_salary=0;
	for(auto iter = employees.begin() ; iter != employees.end() ; ++iter) {

		team_salary=team_salary+(*iter)->getSalary();

	}
	return team_salary;
}


std::vector<std::shared_ptr<Employee> > Department::getEmployees() const
{
	return employees;
}

std::shared_ptr<Employee> Department::findEmployeeById(int id) const
{
	for(auto iter = employees.begin() ; iter != employees.end() ; ++iter) {

		if((*iter)->getId()==id) {
			return (*iter);
		}

	}
	return nullptr;
}

std::string Department::getName() const
{
	return name;
}
