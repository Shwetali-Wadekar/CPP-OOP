#ifndef HRMANAGER_H_
#define HRMANAGER_H_

#include <string>
#include "Company.h"

/**
     * Represents an HR manager responsible for managing the company.
 */
class HRManager {
private:
    std::string name;
    Company& company;

public:
    /**
     * Initializes a new HR manager with the given name.
     *
     * @param name the HR manager's name
     * @param company the company managed by the HR manager
     */
    HRManager(const std::string& name, Company& company);

    /**
     * Returns the HR manager's name.
     *
     * @return the HR manager's name
     */
    std::string getName() const;

    /**
     * Adds a department to the company.
     *
     * @param departmentName the department's name
     */
    void addDepartmentToCompany(const std::string& departmentName);

    /**
     * Adds an employee to a department.
     *
     * @param departmentName the department's name
     * @param employeeName the employee's name
     * @param employeeId the employee's ID
     * @param salary the employee's salary
     */
    void addEmployeeToDepartment(const std::string& departmentName, const std::string& employeeName, const std::string& employeeId, float salary);

    /**
     * Removes an employee from a department.
     *
     * @param departmentName the department's name
     * @param employeeId the employee's ID
     */
    void removeEmployeeFromDepartment(const std::string& departmentName, const std::string& employeeId);
};

#endif /* HRMANAGER_H_ */
