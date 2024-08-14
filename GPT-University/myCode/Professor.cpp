/*
 * Professor.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Professor.h"
#include "Course.h"
Professor::Professor(std::string name) : name(name)
{
}

void Professor::addCourse(Course *course)
{
	courses.push_back(course);
}

void Professor::addSpecialty(const std::string &specialty)
{
	specialties.insert(specialty);
}

std::string Professor::getName() const
{
	return name;
}

std::vector<Course*> Professor::getCourses() const
{
	return courses;
}

std::set<std::string> Professor::getSpecialties() const
{
	return specialties;
}
