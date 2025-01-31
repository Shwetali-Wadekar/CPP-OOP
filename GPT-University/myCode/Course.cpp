/*
 * Course.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Course.h"
#include "Student.h"
#include <stdexcept>
Course::Course(std::string name) : name(name)
{
}

void Course::enrollStudent(std::shared_ptr<Student> student)
{
	enrolledStudents.insert(std::make_pair(student->getId(),student));
}

std::string Course::getName() const
{
	return this->name;
}

std::map<int, std::shared_ptr<Student> > Course::getEnrolledStudents() const
{
	return enrolledStudents;
}

void Course::assignGrade(int studentID, char grade)
{
	auto found=enrolledStudents.find(studentID);

	if( found != enrolledStudents.end()) {
		found->second->addGrade(this,grade);
	}else {
		throw std::invalid_argument ("student does not enroll for this course");
	}

}

char Course::getGrade(int studentID)
{
	auto found=enrolledStudents.find(studentID);

	if( found != enrolledStudents.end()) {
		//Course* c=this;
		return found->second->getGrade(this);
	}else {
		throw std::invalid_argument ("student does not enroll for this course");
	}
}
