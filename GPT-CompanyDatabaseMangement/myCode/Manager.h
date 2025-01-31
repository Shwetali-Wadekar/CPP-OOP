/*
 * Manager.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include<vector>
#include<memory>

#include "Employee.h"

/**
 * Represents a manager, who is also an employee but with additional responsibilities.
 */
class Manager : public Employee {
private:
    std::vector<std::shared_ptr<Employee>> teamMembers;

public:
    /**
     * Initializes a manager with the given name, id, salary, and team members.
     */
    Manager(std::string name, int id, float salary);

    /**
     * Adds an employee to the manager's team.
     */
    void addTeamMember(std::shared_ptr<Employee> employee);

    /**
     * Calculates the total salary of the team members.
     */
    float teamSalary() const;

    /**
     * Returns the list of team members.
     */
    std::vector<std::shared_ptr<Employee>> getTeamMembers() const;

    /**
     * Finds the employee with the highest salary in the team.
     * Returns nullptr if there are no team members.
     */
    std::shared_ptr<Employee> findHighestPaidMember() const;
};

#endif /* MANAGER_H_ */
