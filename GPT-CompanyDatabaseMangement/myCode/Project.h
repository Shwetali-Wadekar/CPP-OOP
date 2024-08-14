/*
 * Project.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef PROJECT_H_
#define PROJECT_H_


#include <string>
#include <memory>
#include <vector>
class Employee;
/**
 * Represents a project in the company.
 */
class Project {
private:
    std::string name;
    float budget;
    std::vector<std::shared_ptr<Employee>> teamMembers;

public:
    /**
     * Initializes a project with the given name and budget.
     */
    Project(std::string name, float budget);

    /**
     * Adds a team member to the project.
     */
    void addTeamMember(std::shared_ptr<Employee> employee);

    /**
     * Returns the total salary spent on team members.
     */
    float totalSalary() const;

    /**
     * Gets a list of all team members.
     */
    std::vector<std::shared_ptr<Employee>> getTeamMembers() const;

    /**
     * Returns the project name.
     */
    std::string getName() const;

    /**
     * Returns the budget remaining after paying the team members.
     */
    float remainingBudget() const;
};

#endif /* PROJECT_H_ */
