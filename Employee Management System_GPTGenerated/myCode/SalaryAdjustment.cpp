/*
 * SalaryAdjustment.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "SalaryAdjustment.h"
#include "CompanyException.h"
SalaryAdjustment::SalaryAdjustment(Company &company) : company(company)
{
}
/**
 * Adjusts the salaries of employees in the specified department based on their performance.
 *
 * @param departmentName the name of the department
 * @param performanceRatings a map of employee IDs to their performance ratings
 * @throws std::invalid_argument if the department or any employee is not found
 */
void SalaryAdjustment::adjustSalaries(const std::string &departmentName,
		const std::map<std::string, float> &performanceRatings)
{
	//performanceRatings
	if ( company.findDepartmentByName(departmentName) != nullptr) {
		auto allEmployee=company.findDepartmentByName(departmentName)->allemployees();

		for(auto i= performanceRatings.begin() ; i != performanceRatings.end() ; ++i) {

			if(company.findDepartmentByName(departmentName)->findEmployeeById((*i).first) != nullptr) {
				company.findDepartmentByName(departmentName)->findEmployeeById((*i).first)->setSalary((*i).second);
			}else {
				throw CompanyException ("employee not exist");

			}
		}

	}else {
		throw CompanyException ("department not exist");
	}
}
