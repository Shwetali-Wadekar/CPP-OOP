/*
 * Professor.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef PROFESSOR_H_
#define PROFESSOR_H_


#include <string>
#include <vector>
#include <set>

class Course; // Forward declaration

class Professor {
private:
    std::string name;
    std::vector<Course*> courses;
    std::set<std::string> specialties;

public:
    Professor(std::string name);

    void addCourse(Course* course);
    void addSpecialty(const std::string& specialty);
    std::string getName() const;
    std::vector<Course*> getCourses() const;
    std::set<std::string> getSpecialties() const;
};
#endif /* PROFESSOR_H_ */
