/*
 * Course.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef COURSE_H_
#define COURSE_H_


#include <string>
#include <map>
#include <memory>

class Student; // Forward declaration

class Course {
private:
    std::string name;
    std::map<int, std::shared_ptr<Student>> enrolledStudents; // student ID to Student pointer

public:
    Course(std::string name);

    void enrollStudent(std::shared_ptr<Student> student);
    std::string getName() const;
    std::map<int, std::shared_ptr<Student>> getEnrolledStudents() const;
    void assignGrade(int studentID, char grade);
    char getGrade(int studentID);
};

#endif /* COURSE_H_ */
