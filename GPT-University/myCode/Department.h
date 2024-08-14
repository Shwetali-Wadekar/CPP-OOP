/*
 * Department.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_


#include <string>
#include <vector>
#include <memory>

class Professor; // Forward declaration
class Course; // Forward declaration

class Department {
private:
    std::string name;
    std::vector<std::unique_ptr<Professor>> professors;
    std::vector<std::unique_ptr<Course>> courses;

public:
    Department(std::string name);

    void addProfessor(std::unique_ptr<Professor> professor);
    void addCourse(std::unique_ptr<Course> course);
    std::string getName() const;
    std::vector<Professor*> getProfessors() const;
    std::vector<Course*> getCourses() const;
    Professor* findProfessor(const std::string& name) const;
    Course* findCourse(const std::string& name) const;
};


#endif /* DEPARTMENT_H_ */
