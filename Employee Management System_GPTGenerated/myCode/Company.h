#ifndef COMPANY_H_
#define COMPANY_H_

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "Department.h"

/**
 * Represents a company with multiple departments.
 */
class Company {
private:
    std::vector<std::unique_ptr<Department>> departments;

public:
    /**
     * Adds a department to the company.
     *
     * @param department the department to add
     */
    void addDepartment(std::unique_ptr<Department> department);

    /**
     * Finds a department by its name.
     *
     * @param name the department's name
     * @return a pointer to the department if found, nullptr otherwise
     */
    Department* findDepartmentByName(const std::string& name);

    /**
     * Generates a report of all employees in the company.
     *
     * @return a string containing the report
     */
    std::string generateEmployeeReport() const;

    /**
     * Calculates the total salary expenditure for the company.
     *
     * @return the total salary expenditure
     */
    float calculateTotalSalary() const;
};

#endif /* COMPANY_H_ */
