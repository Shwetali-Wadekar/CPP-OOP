#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <stdexcept>
#include <map>
#include <Poco/DateTime.h>
#include "Patient.h"
#include "Doctor.h"
#include "Hospital.h"
#include "Administrator.h"
#include "Appointment.h"
#include "HealthcareException.h"
#include <Poco/DateTime.h>
using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, const string &failedMessage)
{
	if (!condition)
	{
		cout << failedMessage << endl;
	}
}

void patientTests()
{
	/**
	 * Tests for the Patient class. (10 points)
	 * - Create a Patient instance.
	 * - Assert the getters return the expected values.
	 * - Change the age and assert the new value.
	 */

	Patient patrick("Patrick", "1119", 26);
	assertTrue(patrick.getName() == "Patrick", "getName not working");
	assertTrue(patrick.getPatientId() == "1119", "getPatientId not working");
	assertTrue(patrick.getAge() == 26, "getAge not working");
	patrick.setAge(25);
	assertTrue(patrick.getAge() == 25, "getAge not working");
}

void doctorTests()
{
	/**
	 * Tests for the Doctor class. (10 points)
	 * - Create a Doctor instance.
	 * - Add patients to the doctor and assert they are added correctly.
	 * - Remove patients by ID and assert they are removed correctly.
	 * - Find patients by ID and assert the correct patient is returned.
	 */
	Doctor ana("Ana", "01");
	std::unique_ptr<Patient> nil(new Patient("Nil", "1200", 20));
	ana.addPatient(move(nil));
	assertTrue(ana.findPatientById("1200")->getPatientId() == "1200",
			"Patient not added successfully");
	ana.removePatient("1200");
	assertTrue(ana.findPatientById("1200")->getPatientId() == "1200",
			"Patient not found");
	std::unique_ptr<Patient> patrick(new Patient("Patrick", "1119", 26));
	assertTrue(ana.findPatientById("1119")->getName() == "Patrick",
			"Patient not found correctly");
}

void hospitalTests()
{
	/**
	 * Tests for the Hospital class. (20 points)
	 * - Add doctors to the hospital.
	 * - Add patients to doctors.
	 * - Generate a doctor report and assert it contains the correct details.
	 * - Calculate the total number of patients and assert the correct value.
	 */
	Hospital gov;
	std::unique_ptr<Doctor> eli(new Doctor("Eli", "02"));
	gov.addDoctor(move(eli));
	assertTrue(gov.findDoctorById("02")->getDoctorId() == "02",
			"Doctor not added to the hostpial.");
	std::unique_ptr<Patient> pablo(new Patient("Pablo", "1100", 21));
	eli->addPatient(move(pablo));
	assertTrue(eli->findPatientById("1100")->getName() == "Pablo",
			"Patient not added to the doctor.");
	gov.generateDoctorReport();

	assertTrue(gov.calculateTotalPatients() == 1, "Patients count not correct");
}

void administratorTests()
{
	/**
	 * Tests for the Administrator class. (10 points)
	 * - Add doctors and patients via the administrator.
	 * - Remove patients via the administrator.
	 */
	Hospital gov;
	std::unique_ptr<Doctor> eli(new Doctor("Eli", "02"));
	unique_ptr<Doctor> phil(new Doctor("Phil", "P01"));
		unique_ptr<Doctor> doctorBhavin(new Doctor("bhavin","D01"));
		unique_ptr<Doctor> doctorDev(new Doctor("dev","D02"));

		std::unique_ptr<Patient> pablo(new Patient("Pablo", "1100", 21));
		std::unique_ptr<Patient> claire(new Patient("Claire", "c01", 23));
		std::unique_ptr<Patient> nil(new Patient("Nil", "1200", 20));

		std::unique_ptr<Patient> rutvik(new Patient("rutvik","P01",23));
		std::unique_ptr<Patient> rutviknoBhai(new Patient("hutvik","P02",20));
		std::unique_ptr<Patient> apurva(new Patient("apurva","P03",27));


		gov.addDoctor(move(eli));
		gov.addDoctor(move(phil));
		gov.findDoctorById("02")->addPatient(move(pablo));
		gov.findDoctorById("P01")->addPatient(move(claire));
		gov.findDoctorById("02")->addPatient(move(nil));
		Administrator admin("admin", gov);
		admin.removePatientFromDoctor("02","1200");
		cout<<gov.generateDoctorReport();
		admin.addPatientToDoctor("02","Emmy","E03",27);
		cout<<gov.generateDoctorReport();
		admin.addDoctorToHospital("anton","D03");
		cout<<gov.generateDoctorReport();


}

void appointmentTests()
{
	/**
	 * Tests for the Appointment class. (15 points)
	 * - Create an Appointment instance.
	 * - Assert the getters return the expected values.
	 * - Reschedule the appointment and assert the new date.
	 */

	unique_ptr<Doctor> phil(new Doctor("Phil", "P01"));
	std::unique_ptr<Patient> claire(new Patient("Claire", "c01", 23));

	Appointment app(claire.get(), phil.get(), Poco::DateTime(2024, 8, 2));
	assertTrue(app.getAppointmentDate() == Poco::DateTime(2024, 8, 2),
			"getter not correct");
	app.reschedule(Poco::DateTime(2024, 8, 3));
	assertTrue(app.getAppointmentDate() == Poco::DateTime(2024, 8, 3),
			"getter not correct");

}

void exceptionHandleTests()
{
	/**
	 * Tests for exception handling. (5 points)
	 * - Attempt to add a patient to a non-existent doctor and catch the exception.
	 * - Attempt to remove a non-existent patient and catch the exception.
	 */

}

void allTests()
{
	patientTests();
	doctorTests();
	hospitalTests();
	administratorTests();
	appointmentTests();
	exceptionHandleTests();
}

