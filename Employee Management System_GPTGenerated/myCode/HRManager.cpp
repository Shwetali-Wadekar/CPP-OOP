/*
 * HRManager.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "HRManager.h"
#include "CompanyException.h"
HRManager::HRManager(const std::string &name, Company &company) : name(name) , company(company)
{
}

std::string HRManager::getName() const
{
	return this->name;
}

void HRManager::addDepartmentToCompany(const std::string &departmentName)
{
	std::unique_ptr<Department> department(new Department(departmentName));
	company.addDepartment(std::move(department));
}

void HRManager::addEmployeeToDepartment(const std::string &departmentName,
		const std::string &employeeName, const std::string &employeeId,
		float salary)
{
	std::unique_ptr<Employee> employee(new Employee(employeeName,employeeId,salary));

	if ( company.findDepartmentByName(departmentName) != nullptr) {

		company.findDepartmentByName(departmentName)->addEmployee(std::move(employee));
	}
	else {
		throw CompanyException ("department not exist");
	}
}

void HRManager::removeEmployeeFromDepartment(const std::string &departmentName,
		const std::string &employeeId)
{
	if ( company.findDepartmentByName(departmentName) != nullptr) {

		company.findDepartmentByName(departmentName)->removeEmployee(employeeId);}
	else {
		throw CompanyException ("department not exist");
	}
}
