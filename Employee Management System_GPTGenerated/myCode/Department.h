#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include <string>
#include <vector>
#include <memory>
#include "Employee.h"

/**
 * Represents a department within a company.
 */
class Department {
private:
    std::string name;
    std::vector<std::unique_ptr<Employee>> employees;

public:
    /**
     * Initializes a new department with the given name.
     *
     * @param name the department's name
     */
    Department(const std::string& name);

    /**
     * Returns the department's name.
     *
     * @return the department's name
     */
    std::string getName() const;

    /**
     * Adds an employee to the department.
     *
     * @param employee the employee to add
     */
    void addEmployee(std::unique_ptr<Employee> employee);

    /**
     * Removes an employee from the department by ID.
     *
     * @param id the employee's ID
     * @throws std::invalid_argument if the employee is not found
     */
    void removeEmployee(const std::string& id);

    /**
     * Returns a pointer to the employee with the given ID.
     *
     * @param id the employee's ID
     * @return a pointer to the employee, or nullptr if not found
     */
    Employee* findEmployeeById(const std::string& id);

    std::vector<Employee*> allemployees();
};

#endif /* DEPARTMENT_H_ */
