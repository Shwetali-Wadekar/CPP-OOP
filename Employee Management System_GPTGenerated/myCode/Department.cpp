/*
 * Department.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "Department.h"
#include "CompanyException.h"
Department::Department(const std::string &name) :name(name)
{
}

std::string Department::getName() const
{
	return name;
}

void Department::addEmployee(std::unique_ptr<Employee> employee)
{
	employees.push_back(std::move(employee));
}

void Department::removeEmployee(const std::string &id)
{
	auto foundIter=employees.begin();
	bool flag=false;
	for(auto iter = employees.begin() ; iter != employees.end() ; ++iter) {

		if((**iter).getId() == id) {
			flag=true;
			foundIter=iter;
		}

	}
	if(flag) {
		employees.erase(foundIter);
	}else {
		throw CompanyException ("employee not found!!");
	}
}

Employee* Department::findEmployeeById(const std::string &id)
{
	for(auto iter = employees.begin() ; iter != employees.end() ; ++iter) {
		if((**iter).getId() == id) {
			return (*iter).get();
		}
	}
	return nullptr;
}

std::vector<Employee*> Department::allemployees()
{
	std::vector<Employee*> allemployee;
	for(auto iter = employees.begin() ; iter != employees.end() ; ++iter) {
		allemployee.push_back(iter->get());
	}
	return allemployee;

}
