#ifndef SALARYADJUSTMENT_H_
#define SALARYADJUSTMENT_H_

#include <string>
#include "Company.h"

/**
 * Provides functionalities to adjust salaries based on performance.
 */
class SalaryAdjustment {
private:
    Company& company;

public:
    /**
     * Initializes a new SalaryAdjustment with the given company.
     *
     * @param company the company whose salaries will be adjusted
     */
    SalaryAdjustment(Company& company);

    /**
     * Adjusts the salaries of employees in the specified department based on their performance.
     *
     * @param departmentName the name of the department
     * @param performanceRatings a map of employee IDs to their performance ratings
     * @throws std::invalid_argument if the department or any employee is not found
     */
    void adjustSalaries(const std::string& departmentName, const std::map<std::string, float>& performanceRatings);
};

#endif /* SALARYADJUSTMENT_H_ */
