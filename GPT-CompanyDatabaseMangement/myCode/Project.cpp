/*
 * Project.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "Project.h"
#include "Employee.h"
Project::Project(std::string name, float budget) : name(name), budget(budget)
{
}

void Project::addTeamMember(std::shared_ptr<Employee> employee)
{
	this->teamMembers.push_back(employee);
}

float Project::totalSalary() const
{
	float team_salary=0;
	for(auto iter = teamMembers.begin() ; iter != teamMembers.end() ; ++iter) {

		team_salary=team_salary+(*iter)->getSalary();

	}
	return team_salary;
}


std::vector<std::shared_ptr<Employee> > Project::getTeamMembers() const
{
	return this->teamMembers;
}

std::string Project::getName() const
{
	return name;
}

float Project::remainingBudget() const
{
	return budget-totalSalary();
}
