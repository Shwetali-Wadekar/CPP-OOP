#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <stdexcept>
#include <map>
#include "Employee.h"
#include "Department.h"
#include "Company.h"
#include "HRManager.h"
#include "SalaryAdjustment.h"
#include "CompanyException.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, const string& failedMessage) {
	if (!condition) {
		cout << failedMessage << endl;
	}
}

void employeeTests() {
	/**
	 * Tests for the Employee class. (10 points)
	 * - Create an Employee instance.
	 * - Assert the getters return the expected values.
	 * - Change the salary and assert the new value.
	 */
	Employee rutvik("Rutvik","25",850);

	assertTrue(rutvik.getId()== "25", "id getter wrong");
	assertTrue(rutvik.getName() == "Rutvik","name getter wrong");
	assertTrue(rutvik.getSalary() == 850,"salary getter wrong");

	rutvik.setSalary(5000);
	assertTrue(rutvik.getSalary() == 5000,"salary getter wrong");




}

void departmentTests() {
	/**
	 * Tests for the Department class. (10 points)
	 * - Create a Department instance.
	 * - Add employees to the department and assert they are added correctly.
	 * - Remove employees by ID and assert they are removed correctly.
	 * - Find employees by ID and assert the correct employee is returned.
	 */
	std::unique_ptr<Employee> rutvik(new Employee("Rutvik","25",850));
	std::unique_ptr<Employee> bhavin(new Employee("Bhavin","1",1850));
	std::unique_ptr<Employee> dev(new Employee("Dev","19",2850));

	Department plant("Plant Engineering");
	plant.addEmployee(std::move(rutvik));
	plant.addEmployee(std::move(bhavin));
	plant.addEmployee(std::move(dev));

	assertTrue(plant.findEmployeeById("25")!=nullptr,"employee should be found");
	assertTrue(plant.findEmployeeById("1")!=nullptr,"employee should be found");
	assertTrue(plant.findEmployeeById("19")!=nullptr,"employee should be found");

	plant.removeEmployee("19");
	assertTrue(plant.findEmployeeById("19")==nullptr,"employee not removed");

	assertTrue(plant.findEmployeeById("25")->getName()=="Rutvik","incorrect employee returned");



}

void companyTests() {
	/**
	 * Tests for the Company class. (20 points)
	 * - Add departments to the company.
	 * - Add employees to departments.
	 * - Generate an employee report and assert it contains the correct details.
	 * - Calculate the total salary expenditure and assert the correct value.
	 */
	unique_ptr<Department> plant(new Department("PlantEngineering"));
	unique_ptr<Department> automation(new Department("automation"));

	std::unique_ptr<Employee> rutvik(new Employee("Rutvik","25",1000));
	std::unique_ptr<Employee> bhavin(new Employee("Bhavin","1",200));
	std::unique_ptr<Employee> dev(new Employee("Dev","19",300));
	std::unique_ptr<Employee> apurva(new Employee("Apurva","21",500));

	plant->addEmployee(std::move(rutvik));
	plant->addEmployee(std::move(bhavin));
	automation->addEmployee(std::move(dev));
	automation->addEmployee(std::move(apurva));

	Company prajapatiGmbh;
	prajapatiGmbh.addDepartment(move(plant));
	prajapatiGmbh.addDepartment(move(automation));
	cout<<prajapatiGmbh.generateEmployeeReport()<<endl;

	string expected_report="25: Rutvik, 1: Bhavin, 19: Dev, 21: Apurva, ";

	assertTrue(prajapatiGmbh.generateEmployeeReport()==expected_report,"report not as expected");
	assertTrue(prajapatiGmbh.calculateTotalSalary()==2000,"total salary not as expected");


	// hrManagerTests

	HRManager hr("hr",prajapatiGmbh);
	hr.addDepartmentToCompany("power");

	std::unique_ptr<Employee> supriya(new Employee("Supriya","29",10000));

	assertTrue(prajapatiGmbh.findDepartmentByName("power")!=nullptr,"department not added by hr");
	hr.addEmployeeToDepartment("power",supriya->getName(),supriya->getId(),supriya->getSalary());
	cout<<prajapatiGmbh.generateEmployeeReport()<<endl;

	hr.removeEmployeeFromDepartment("automation","21");
	cout<<prajapatiGmbh.generateEmployeeReport()<<endl;


	//salaryAdjustmentTests
	SalaryAdjustment ad(prajapatiGmbh);

	std::map<std::string, float> performanceRatings = { {"1",2000}, {"25",100}};

	ad.adjustSalaries("PlantEngineering",performanceRatings);

	cout<<prajapatiGmbh.findDepartmentByName("PlantEngineering")->findEmployeeById("1")->getSalary();

	//exceptionHandleTests
	try {
		hr.addEmployeeToDepartment("xyz","try","45",0);
		assertTrue(false,"exception not thrown");
	}catch ( std::exception& e) {

	}

	try {
		hr.removeEmployeeFromDepartment("PlantEngineering","99");
		assertTrue(false,"exception not thrown");
	}catch ( std::exception& e) {

	}

}

void hrManagerTests() {
	/**
	 * Tests for the HRManager class. (10 points)
	 * - Add departments and employees via the HR manager.
	 * - Remove employees via the HR manager.
	 */

	//companyTests();

}

void salaryAdjustmentTests() {
	/**
	 * Tests for the SalaryAdjustment class. (15 points)
	 * - Adjust salaries based on performance ratings.
	 * - Assert the salaries are adjusted correctly based on the given ratings.
	 */
}

void exceptionHandleTests() {
	/**
	 * Tests for exception handling. (5 points)
	 * - Attempt to add an employee to a non-existent department and catch the exception.
	 * - Attempt to remove a non-existent employee and catch the exception.
	 */
}

void allTests() {
	employeeTests();
	departmentTests();
	companyTests();
	hrManagerTests();
	salaryAdjustmentTests();
	exceptionHandleTests();
}
