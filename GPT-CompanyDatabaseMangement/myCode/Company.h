/*
 * Company.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef COMPANY_H_
#define COMPANY_H_


#include <string>
#include <memory>
#include <map>
#include <vector>

class Department;
class Project;

/**
 * Represents a company.
 */
class Company {
private:
    std::string name;
    std::map<std::string, std::shared_ptr<Department>> departments;
    std::vector<std::shared_ptr<Project>> projects;

public:
    /**
     * Initializes a company with the given name.
     */
    Company(std::string name);

    /**
     * Adds a department to the company.
     */
    void addDepartment(std::shared_ptr<Department> department);

    /**
     * Adds a project to the company.
     */
    void addProject(std::shared_ptr<Project> project);

    /**
     * Gets the total salary paid by the company.
     */
    float totalSalary() const;

    /**
     * Gets a list of all departments in the company.
     */
    std::vector<std::shared_ptr<Department>> getDepartments() const;

    /**
     * Gets a list of all projects in the company.
     */
    std::vector<std::shared_ptr<Project>> getProjects() const;

    /**
     * Returns the total remaining budget across all projects.
     */
    float totalRemainingBudget() const;
};


#endif /* COMPANY_H_ */
