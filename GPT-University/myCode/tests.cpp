/*
 * tests.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */



#include "University.h"
#include "Department.h"
#include "Professor.h"
#include "Course.h"
#include "Student.h"
#include<iostream>
#include<memory>
using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the University system classes. (XX points)
 */
void universitySystemTests() {
    /*
     * (1) Create a university "Tech University" with departments "Computer Science", "Mathematics", and "Physics".
     *     Add professors "Prof. Alice" and "Prof. Bob" to "Computer Science", and "Prof. Charlie" to "Mathematics".
     *     Add courses "Algorithms", "Data Structures" to "Computer Science", and "Calculus" to "Mathematics".
     *     Enroll students "Student1" and "Student2" in "Algorithms", and "Student3" in "Calculus".
     *     Assign grades to students and verify GPA calculations.
     *     Use assertions to verify that the university, departments, professors, courses, and students are correctly added and related.
     *     (30 points)
     */
    // TODO
	University hda("Tech University");

	Department* cs=new Department("Computer Science");
	Department* py=new Department("Physics");
	Department* ma=new Department("Mathematics");


	hda.addDepartment(std::unique_ptr<Department>(cs));
	hda.addDepartment(std::unique_ptr<Department>(py));
	hda.addDepartment(std::unique_ptr<Department>(ma));

	Course* algorithm= new Course("Algorithms");
	Course* ds= new Course("Data Structures");
	Course* calculus= new Course("Calculus");
	//Course* algorithm= new Course("Algorithms");

	Professor* profAlice=new Professor("Prof. Alice");
	Professor* profBob=new Professor("Prof. Bob");
	Professor* profCharlie=new Professor("Prof. Charlie");

	cs->addProfessor(std::unique_ptr<Professor>(profAlice));
	cs->addProfessor(std::unique_ptr<Professor>(profBob));

	cs->addCourse(std::unique_ptr<Course>(ds));
	cs->addCourse(std::unique_ptr<Course>(algorithm));

	ma->addProfessor(std::unique_ptr<Professor>(profCharlie));
	ma->addCourse(std::unique_ptr<Course>(calculus));

	std::shared_ptr<Student> student1(new Student(1,"Student1"));
	std::shared_ptr<Student> student2(new Student(2,"Student2"));
	std::shared_ptr<Student> student3(new Student(3,"Student3"));
//
//	auto csCourses=cs->getCourses();
//	cs->findCourse("Algorithms")->enrollStudent(student1);
	//cs->findCourse("Algorithms")->enrollStudent(student2);

//	ma->findCourse("Calculus")->enrollStudent(student3);


	algorithm->enrollStudent(student1);


	algorithm->enrollStudent(student2);
	calculus->enrollStudent(student3);
//
	cs->findCourse("Algorithms")->assignGrade(1,'A');
	cs->findCourse("Algorithms")->assignGrade(2,'B');
	ma->findCourse("Calculus")->assignGrade(3,'C');
////
//
	assertTrue(hda.getDepartments().size()==3,"department should be 3");

	assertTrue(hda.findDepartment("Computer Science")->getCourses().size()==2,"coures are not added");

	assertTrue(hda.findDepartment("Computer Science")->findCourse("Algorithms")->getEnrolledStudents().size()==2,"Students"
			"are not enrolled");
	assertTrue(hda.findDepartment("Computer Science")->findProfessor("Prof. Alice")!=nullptr,"professor not added");


}

/**
 * Tests for the Department class. (XX points)
 */
void departmentTests() {
    /*
     * (1) Create a department "Biology" and add professors "Prof. Eve" and "Prof. Frank".
     *     Add courses "Genetics" and "Microbiology" and enroll students "Student4" and "Student5" in them.
     *     Verify the relationships using assertions.
     *     (25 points)
     */
    // TODO
	Department* biology=new Department("Biology");


	Professor* Eve=new Professor("Prof. Eve");
	Professor* Frank=new Professor("Prof. Frank");

	biology->addProfessor(std::unique_ptr<Professor>(Eve));
	biology->addProfessor(std::unique_ptr<Professor>(Frank));

	Course* Genetics= new Course("Genetics");

	Course* Microbiology= new Course("Microbiology");
	std::shared_ptr<Student> student4(new Student(4,"Student1"));
	std::shared_ptr<Student> student5(new Student(5,"Student5"));

	biology->addCourse(std::unique_ptr<Course>(Genetics));
	biology->addCourse(std::unique_ptr<Course>(Microbiology));

	biology->findCourse("Genetics")->enrollStudent(student4);
	biology->findCourse("Genetics")->enrollStudent(student5);

	biology->findCourse("Microbiology")->enrollStudent(student4);
	biology->findCourse("Microbiology")->enrollStudent(student5);


	assertTrue(biology->getCourses().size()==2,"courses should be 2");
	assertTrue(biology->getProfessors().size()==2,"professors should be 2");


}

/**
 * Tests for the Professor class. (XX points)
 */
void professorTests() {
    /*
     * (1) Create a professor "Prof. Grace" and add courses "Machine Learning" and "Artificial Intelligence".
     *     Add specialties "AI" and "Data Science".
     *     Verify that the professor's courses and specialties are correctly added.
     *     (20 points)
     */
    // TODO
	Professor* prof=new Professor("Prof. Grace");
	Course* ml= new Course("Machine Learning");
	Course* ai= new Course("Artificial Intelligence");
	prof->addCourse(ml);
	prof->addCourse(ai);
	prof->addSpecialty("AI");
	prof->addSpecialty("Data science");
	assertTrue(prof->getCourses().size()==2,"courses are not added");
	assertTrue(prof->getSpecialties().size()==2,"speciallities are not added");

}

/**
 * Tests for the Course class. (XX points)
 */
void courseTests() {
    /*
     * (1) Create a course "Databases" and enroll students "Student6" and "Student7".
     *     Assign grades and verify GPA calculations.
     *     Verify that the students are correctly enrolled and graded using assertions.
     *     (15 points)
     */
    // TODO
	Course course("Databases");
	shared_ptr<Student> student6(new Student(6,"Student6"));
	shared_ptr<Student> student7(new Student(7,"Student7"));
	course.enrollStudent(student6);
	course.enrollStudent(student7);
	course.assignGrade(6,'A');
	course.assignGrade(7,'D');

	assertTrue(course.getGrade(6)=='A',"grade assert failed");
	auto enrolledstudents=course.getEnrolledStudents();
	assertTrue(enrolledstudents.find(6)!=enrolledstudents.end(),"student not exist");
	assertTrue(enrolledstudents.find(7)!=enrolledstudents.end(),"student not exist");


}

/**
 * Tests for the Student class. (XX points)
 */
void studentTests() {
    /*
     * (1) Create a student with ID 2345 and name "Jane Doe".
     *     Enroll the student in multiple courses and assign grades.
     *     Verify the student's ID, name, and GPA using assertions.
     *     (10 points)
     */
    // TODO

	Student jane(2345,"Jane Doe");
	Course* c1= new Course("cs");
	Course* c2= new Course("maths");

	jane.addGrade(c1,'A');
	jane.addGrade(c2,'C');

	assertTrue(jane.getName()=="Jane Doe","name not matched");
	assertTrue(jane.getId()==2345,"ID not matched");
	assertTrue(jane.getGPA(c1)==4,"gpa not matched");
}

/**
 * Comprehensive tests involving multiple relationships. (XX points)
 */
void comprehensiveTests() {
    /*
     * (1) Create a university "Global University" with multiple departments and establish relationships
     *     among professors, courses, and students. Verify the complex relationships and interactions.
     *     (20 points)
     */
    // TODO
}

void allTests() {
    universitySystemTests();
    departmentTests();
    professorTests();
    courseTests();
    studentTests();
    comprehensiveTests();
}

