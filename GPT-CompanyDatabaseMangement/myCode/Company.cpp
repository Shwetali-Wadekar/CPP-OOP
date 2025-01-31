/*
 * Company.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "Company.h"
#include "Department.h"
#include "Employee.h"
#include "Project.h"

Company::Company(std::string name) : name(name)
{
}

void Company::addDepartment(std::shared_ptr<Department> department)
{
	departments.insert(std::make_pair(department->getName(),department));
}

void Company::addProject(std::shared_ptr<Project> project)
{
	projects.push_back(project);
}

float Company::totalSalary() const
{
	float totalSalary=0;
	for(auto iter= departments.begin() ; iter != departments.end() ; ++iter) {

		totalSalary=totalSalary+(*iter).second->totalSalary();

	}
	for(auto iter = projects.begin() ; iter != projects.end() ; ++iter) {
		totalSalary=totalSalary+(*iter)->totalSalary();
	}


	return totalSalary;
}

std::vector<std::shared_ptr<Department> > Company::getDepartments() const
{
	std::vector<std::shared_ptr<Department> > alldepartments;

	for(auto iter = departments.begin() ; iter != departments.end() ; ++iter) {

		alldepartments.push_back((*iter).second);

	}
	return alldepartments;
}

std::vector<std::shared_ptr<Project> > Company::getProjects() const
{
	return this->projects;
}

float Company::totalRemainingBudget() const
{
	float totalremaingbudget=0;
	for(auto iter = projects.begin() ; iter != projects.end() ; ++iter) {

		totalremaingbudget=totalremaingbudget+(*iter)->remainingBudget();

	}
	return totalremaingbudget;
}
