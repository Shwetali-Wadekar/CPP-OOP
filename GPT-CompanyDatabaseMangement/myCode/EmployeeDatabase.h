/*
 * EmployeeDatabase.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef EMPLOYEEDATABASE_H_
#define EMPLOYEEDATABASE_H_


#include <map>
#include <memory>
#include <string>
#include "Employee.h"
#include<vector>
/**
 * Provides a simple database for employees.
 */
class EmployeeDatabase {
private:
    std::map<int, std::shared_ptr<Employee>> employees;

public:
    /**
     * Adds an employee to the database.
     */
    void addEmployee(std::shared_ptr<Employee> employee);

    /**
     * Finds an employee by ID.
     */
    std::shared_ptr<Employee> findEmployeeById(int id) const;

    /**
     * Gets a list of all employees in the database.
     */
    std::map<int, std::shared_ptr<Employee>> getAllEmployees() const;

    /**
     * Finds employees with names that start with a given prefix.
     * Returns a vector of employees whose names start with the prefix.
     */
    std::vector<std::shared_ptr<Employee>> findEmployeesByPrefix(const std::string& prefix) const;
};

#endif /* EMPLOYEEDATABASE_H_ */
