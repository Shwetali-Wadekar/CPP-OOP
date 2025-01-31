/*
 * Student.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Student.h"
#include "course.h"
#include<stdexcept>
std::map<char, float> Student::gradeToGpa = { {'A', 4.0}, {'B', 3.0}, {'C', 2.0}, {'D', 1.0}, {'E', 0.0} };

Student::Student(int id, std::string name) : id(id) , name(name)
{
}

int Student::getId() const
{
	return this->id;
}

std::string Student::getName() const
{
	return this->name;
}

void Student::addGrade(Course *course, char grade)
{
	grades.insert(std::make_pair(course,grade));
}

char Student::getGrade( Course *course) const
{
	 auto found= grades.find(course);

	if(found != grades.end()) {
		return found->second;
	}else {
		std::invalid_argument ("course not exists");
	}
	return ' ';

}

float Student::getGPA(Course* course) const
{
	auto found= this->grades.find(course);
	if(found != grades.end()) {

		auto gptfound=Student::gradeToGpa.find(found->second);
		if( gptfound != gradeToGpa.end()) {
			return gptfound->second;
		}

	}else {
		std::invalid_argument ("course not exists");

	}
	return 0;

}
