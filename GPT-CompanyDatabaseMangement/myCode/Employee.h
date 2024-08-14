/*
 * Employee.h
 *
 *  Created on: 2 Aug 2024
 *      Author: hp
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_


#include <string>
#include <memory>

/**
 * Represents an employee in the company.
 */
class Employee {
private:
    std::string name;
    int id;
    float salary;

public:
    /**
     * Initializes an employee with the given name, id, and salary.
     */
    Employee(std::string name, int id, float salary);

    /**
     * Returns the employee's name.
     */
    std::string getName() const;

    /**
     * Returns the employee's id.
     */
    int getId() const;

    /**
     * Returns the employee's salary.
     */
    float getSalary() const;

    /**
     * Sets the employee's salary.
     */
    void setSalary(float salary);
};
#endif /* EMPLOYEE_H_ */
