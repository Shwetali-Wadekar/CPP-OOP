/*
 * Company.cpp
 *
 *  Created on: Jul 30, 2024
 *      Author: pradh
 */

#include "Company.h"

void Company::addDepartment(std::unique_ptr<Department> department)
{
	departments.push_back(std::move(department));
}

Department* Company::findDepartmentByName(const std::string &name)
{
	for(auto iter = departments.begin() ; iter != departments.end() ; ++iter) {
		if((**iter).getName()==name) {
			return (*iter).get();
		}
	}
	return nullptr;
}

std::string Company::generateEmployeeReport() const
{
	std::string report="";
	for(auto iter = departments.begin() ; iter != departments.end() ; ++iter) {
		//report=report+(**iter).()+",";
		std::vector<Employee*> allemployee=(**iter).allemployees();

		for( auto i=allemployee.begin() ; i != allemployee.end() ; ++i) {
			report= report+(*i)->getId()+": "+(*i)->getName()+", ";
		}
	}
	return report;
}

float Company::calculateTotalSalary() const
{
	float totalSalary=0;
	for(auto iter = departments.begin() ; iter != departments.end() ; ++iter) {
		std::vector<Employee*> allemployee=(**iter).allemployees();

		for( auto i=allemployee.begin() ; i != allemployee.end() ; ++i) {
			totalSalary= totalSalary+(*i)->getSalary();
		}

	}
	return totalSalary;
}
