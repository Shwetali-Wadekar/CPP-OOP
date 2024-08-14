/*
 * Manager.cpp
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#include "Manager.h"

Manager::Manager(std::string name, int id, float salary) : Employee(name,id,salary)
{
}

void Manager::addTeamMember(std::shared_ptr<Employee> employee)
{
	this->teamMembers.push_back(employee);
}

float Manager::teamSalary() const
{
	float team_salary=0;
	for(auto iter = teamMembers.begin() ; iter != teamMembers.end() ; ++iter) {

		team_salary=team_salary+(*iter)->getSalary();

	}
	return team_salary;
}

std::vector<std::shared_ptr<Employee> > Manager::getTeamMembers() const
{
	return teamMembers;
}

std::shared_ptr<Employee> Manager::findHighestPaidMember() const
{
	if(teamMembers.size()==0) {
		return nullptr;
	}

	float highestSalary=0;
	auto highestpaidEmployee=teamMembers.begin();
	for(auto iter = teamMembers.begin() ; iter != teamMembers.end() ; ++iter) {

		if(highestSalary<(*iter)->getSalary()) {
			highestSalary= (*iter)->getSalary();
			highestpaidEmployee=iter;
		}


	}

	return (*highestpaidEmployee);

}
