/*
 * University.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_


#include <string>
#include <vector>
#include <memory>
#include <set>

class Department; // Forward declaration
class Student; // Forward declaration

class University {
private:
    std::string name;
    std::vector<std::unique_ptr<Department>> departments;
    std::set<std::shared_ptr<Student>> students;

public:
    University(std::string name);

    void addDepartment(std::unique_ptr<Department> department);
    void enrollStudent(std::shared_ptr<Student> student);
    std::string getName() const;
    std::vector<Department*> getDepartments() const;
    std::set<std::shared_ptr<Student>> getStudents() const;
    Department* findDepartment(const std::string& name) const;
};


#endif /* UNIVERSITY_H_ */
