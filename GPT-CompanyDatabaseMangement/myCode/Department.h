/*
 * Department.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_


#include <vector>
#include <memory>
#include <string>

class Employee;
/**
 * Represents a department within a company.
 */
class Department {
private:
    std::string name;
    std::vector<std::shared_ptr<Employee>> employees;

public:
    /**
     * Initializes a department with the given name.
     */
    Department(std::string name);

    /**
     * Adds an employee to the department.
     */
    void addEmployee(std::shared_ptr<Employee> employee);

    /**
     * Calculates the total salary of all employees in the department.
     */
    float totalSalary() const;

    /**
     * Gets a list of all employees in the department.
     */
    std::vector<std::shared_ptr<Employee>> getEmployees() const;

    /**
     * Finds and returns the employee with the specified ID.
     */
    std::shared_ptr<Employee> findEmployeeById(int id) const;

    /**
     * Returns the department name.
     */
    std::string getName() const;
};


#endif /* DEPARTMENT_H_ */
