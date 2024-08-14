#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>

/**
 * Represents an employee with a name, ID, and salary.
 */
class Employee {
private:
    std::string name;
    std::string id;
    float salary;

public:
    /**
     * Initializes a new employee with the given name, ID, and salary.
     *
     * @param name the employee's name
     * @param id the employee's ID
     * @param salary the employee's salary
     */
    Employee(const std::string& name, const std::string& id, float salary);

    /**
     * Returns the employee's name.
     *
     * @return the employee's name
     */
    std::string getName() const;

    /**
     * Returns the employee's ID.
     *
     * @return the employee's ID
     */
    std::string getId() const;

    /**
     * Returns the employee's salary.
     *
     * @return the employee's salary
     */
    float getSalary() const;

    /**
     * Sets the employee's salary.
     *
     * @param salary the new salary
     */
    void setSalary(float salary);
};

#endif /* EMPLOYEE_H_ */
