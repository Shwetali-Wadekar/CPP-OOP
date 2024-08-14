/*
 * University.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "University.h"
#include "Department.h"
#include "Course.h"
#include "Professor.h"

using namespace std;

//    std::string name;
//    std::vector<std::unique_ptr<Department>> departments;
//    std::set<std::shared_ptr<Student>> students;
University::University(std::string name) : name(name)
{
}

void University::addDepartment(std::unique_ptr<Department> department)
{
	departments.push_back(move(department));
}

void University::enrollStudent(std::shared_ptr<Student> student)
{
	students.insert(student);
}

std::string University::getName() const
{
	return name;
}

std::vector<Department*> University::getDepartments() const
{
	std::vector<Department*> allDepartments;

	for(auto iter = departments.begin() ; iter != departments.end() ; ++iter) {
		allDepartments.push_back((*iter).get());
	}
	return allDepartments;
}

std::set<std::shared_ptr<Student> > University::getStudents() const
{	std::set<std::shared_ptr<Student>> allStudents;
	for(auto iter = students.begin() ; iter != students.end() ; ++iter) {
		allStudents.insert((*iter));
	}
	return allStudents;
}

Department* University::findDepartment(const std::string &name) const
{

	for(auto iter= departments.begin() ; iter != departments.end() ; ++iter) {
		if((*iter)->getName()==name) {
			return (*iter).get();
		}
	}
	return nullptr;

}
