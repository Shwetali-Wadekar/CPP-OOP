/*
 * EmployeeDatabase.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "EmployeeDatabase.h"

void EmployeeDatabase::addEmployee(std::shared_ptr<Employee> employee)
{
	employees.insert(std::make_pair(employee->getId(),employee));
}

std::shared_ptr<Employee> EmployeeDatabase::findEmployeeById(int id) const
{
	auto found=employees.find(id);

	if(found != employees.end()) {
		return found->second;
	}
	return nullptr;

}

std::map<int, std::shared_ptr<Employee> > EmployeeDatabase::getAllEmployees() const
{
	return employees;
}

std::vector<std::shared_ptr<Employee> > EmployeeDatabase::findEmployeesByPrefix(
		const std::string &prefix) const
{
	std::vector<std::shared_ptr<Employee>> samePrefixEmployees;

	for(auto iter = employees.begin() ; iter != employees.end() ; ++iter) {

		std::string name= (*iter).second->getName();

		if(name.find(prefix) != std::string::npos) {

			samePrefixEmployees.push_back((*iter).second);

		}

	}

	return samePrefixEmployees;
}
