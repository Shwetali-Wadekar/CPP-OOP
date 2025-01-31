/*
 * Department.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Department.h"
#include "Professor.h"
#include "Course.h"
Department::Department(std::string name) : name(name)
{
}

void Department::addProfessor(std::unique_ptr<Professor> professor)
{
	professors.push_back(std::move(professor));
}

void Department::addCourse(std::unique_ptr<Course> course)
{
	courses.push_back(std::move(course));
}

std::string Department::getName() const
{
	return name;
}

std::vector<Professor*> Department::getProfessors() const
{std::vector<Professor*> allprofessors;
	for(auto i=professors.begin() ; i != professors.end() ; ++i) {
		allprofessors.push_back((*i).get());
	}
	return allprofessors;
}

std::vector<Course*> Department::getCourses() const
{

	std::vector<Course*>  allcourses;
	for(auto iter = courses.begin(); iter != courses.end()  ; ++iter) {
		allcourses.push_back((*iter).get());
	}
	return allcourses;
}

Professor* Department::findProfessor(const std::string &name) const
{
	for(auto iter= professors.begin() ; iter != professors.end() ; ++iter) {
		if((*iter)->getName()==name) {
			return (*iter).get();
		}
	}
	return nullptr;
}

Course* Department::findCourse(const std::string &name) const
{
	for(auto iter= courses.begin() ; iter != courses.end() ; ++iter) {
		if((*iter)->getName()==name) {
			return (*iter).get();
		}
	}
	return nullptr;
}
