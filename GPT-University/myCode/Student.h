/*
 * Student.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef STUDENT_H_
#define STUDENT_H_


#include <string>
#include <map>

class Course; // Forward declaration

class Student {
private:
    int id;
    std::string name;
    std::map<Course*, char> grades; // Course pointer to grade

public:
    static std::map<char,float> gradeToGpa;
    Student(int id, std::string name);

    int getId() const;
    std::string getName() const;
    void addGrade(Course* course, char grade);
    char getGrade( Course* course) const;
    float getGPA(Course* course) const; // Calculate GPA based on grades
};
#endif /* STUDENT_H_ */
