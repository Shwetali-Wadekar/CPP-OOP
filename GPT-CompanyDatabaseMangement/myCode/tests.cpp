#include <iostream>
#include <memory>
#include <vector>
#include <cassert>
#include "Company.h"
#include "Employee.h"
#include "Manager.h"
#include "Department.h"
#include "Project.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, const std::string& failedMessage) {
    if (!condition) {
        std::cout << failedMessage << std::endl;
    }
}

/**
 * Tests for the Employee class. (20 points)
 */
void employeeTests() {
    // Create an instance of Employee

    // 1. Verify the name, id, and salary retrieval.
	Employee bhavin("bhavin",1,2150);
	assertTrue(bhavin.getId()==1,"id not matched");
	assertTrue(bhavin.getName()=="bhavin","name is matched");
	assertTrue(bhavin.getSalary()==2150,"salary not matched");

    // 2. Test salary update.
	bhavin.setSalary(3150);
	assertTrue(bhavin.getSalary()==3150,"salary not matched");

}

/**
 * Tests for the Manager class. (20 points)
 */
void managerTests() {
    // Create an instance of Manager

    // 1. Verify the name, id, and salary retrieval.
	Manager bhavin("dev",07,750);
	assertTrue(bhavin.getId()==7,"id not matched");
	assertTrue(bhavin.getName()=="dev","name is matched");
	assertTrue(bhavin.getSalary()==750,"salary not matched");



    // 2. Add team members and verify.
	Employee* em1= new Employee("bhavin",101,1250);
	Employee* em2= new Employee("apurva",102,1250);
	Employee* em3= new Employee("rutvik",103,2250);

	bhavin.addTeamMember(std::shared_ptr<Employee>(em1));
	bhavin.addTeamMember(std::shared_ptr<Employee>(em2));
	bhavin.addTeamMember(std::shared_ptr<Employee>(em3));


    // 3. Verify highest-paid team member.
	assertTrue(bhavin.findHighestPaidMember()->getId()==103,"highest paid employee not correct");

}

/**
 * Tests for the Department class. (20 points)
 */
void departmentTests() {
    // Create an instance of Department
	Department dep1("plantEngineering");

    // 1. Verify the department name retrieval.
	assertTrue(dep1.getName()=="plantEngineering","department not matched!");


    // 2. Add employees and verify.
	Employee* em1= new Employee("bhavin",101,1250);
	Employee* em2= new Employee("apurva",102,1250);
	Employee* em3= new Employee("rutvik",103,2250);

	dep1.addEmployee(std::shared_ptr<Employee>(em1));
	dep1.addEmployee(std::shared_ptr<Employee>(em2));
	dep1.addEmployee(std::shared_ptr<Employee>(em3));

	assertTrue(dep1.getEmployees().size()==3,"employee not added to departments");

	assertTrue(dep1.findEmployeeById(102)!= nullptr,"employee should be in the department");
	assertTrue(dep1.totalSalary()==(1250+1250+2250),"total salary wrong");
}

/**
 * Tests for the Project class. (20 points)
 */
void projectTests() {
    // Create an instance of Project


    // 1. Verify the project name and description retrieval.
	Project cv("cv",10000);



    // 2. Add employees and verify.

	Employee* em1= new Employee("bhavin",101,1250);
	Employee* em2= new Employee("apurva",102,1250);
	Employee* em3= new Employee("rutvik",103,2250);

	cv.addTeamMember(std::shared_ptr<Employee>(em1));
	cv.addTeamMember(std::shared_ptr<Employee>(em2));
	cv.addTeamMember(std::shared_ptr<Employee>(em3));


	float expectedRemainingBudget= 10000-1250-1250-2250;
	assertTrue(cv.remainingBudget()==expectedRemainingBudget,"remaining budget incorrect");

	//cout<<cv.remainingBudget();


}

/**
 * Tests for the Company class. (20 points)
 */
void companyTests() {
    // Create an instance of Company
	Company ltts("ltts");

    // 1. Verify the company name retrieval.

    // 2. Add departments and verify.
	Department* dep1=new Department("plantEngineering");

    // 1. Verify the department name retrieval.
	//assertTrue(dep1->getName()=="plantEngineering","department not matched!");


    // 2. Add employees and verify.
	Employee* em1= new Employee("bhavin",101,1250);
	Employee* em2= new Employee("apurva",102,1250);
	Employee* em3= new Employee("rutvik",103,2250);

	dep1->addEmployee(std::shared_ptr<Employee>(em1));
	dep1->addEmployee(std::shared_ptr<Employee>(em2));
	dep1->addEmployee(std::shared_ptr<Employee>(em3));

	ltts.addDepartment(std::shared_ptr<Department>(dep1));

	Project* cv=new Project("cv",10000);



    // 2. Add employees and verify.

	Employee* em4= new Employee("supriya",101,5050);
	Employee* em5= new Employee("anton",102,5000);
	Employee* em6= new Employee("hutvik",103,4050);

	cv->addTeamMember(std::shared_ptr<Employee>(em4));
	cv->addTeamMember(std::shared_ptr<Employee>(em5));
	cv->addTeamMember(std::shared_ptr<Employee>(em6));

	ltts.addProject(std::shared_ptr<Project>(cv));
	float totalSalaryOfCompany=1250+1250+2250+5050+5000+4050;
	assertTrue(ltts.totalSalary()==totalSalaryOfCompany,"total salary of company not matched");

    // 3. Add projects and verify.

}

/**
 * Run all tests. (40 points)
 */
void alltest() {
    employeeTests();
    managerTests();
    departmentTests();
    projectTests();
    companyTests();
}

