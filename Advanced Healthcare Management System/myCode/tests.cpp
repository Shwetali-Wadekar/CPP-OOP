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
void assertTrue(bool condition, const string& failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

void patientTests() {
/**
 * Tests for the Patient class. (10 points)
 * - Create a Patient instance.
 * - Assert the getters return the expected values.
 * - Change the age and asser
 * t the new value.
 */

	Patient rutvik("rutvik","P01",23);
	assertTrue(rutvik.getAge()==23,"getter is not working");
	assertTrue(rutvik.getName()=="rutvik","getter is not working");
	assertTrue(rutvik.getPatientId()=="P01","getter is not working");


}

void doctorTests() {
/**
 * Tests for the Doctor class. (10 points)
 * - Create a Doctor instance.
 * - Add patients to the doctor and assert they are added correctly.
 * - Remove patients by ID and assert they are removed correctly.
 * - Find patients by ID and assert the correct patient is returned.
 */

	Doctor doctor("bhavin","D01");
	std::unique_ptr<Patient> rutvik(new Patient("rutvik","P01",23));
	doctor.addPatient(move(rutvik));
	assertTrue(doctor.findPatientById("P01")->getName()=="rutvik","patient not added successfully");
	doctor.removePatient("P01");
	assertTrue(doctor.findPatientById("P01")==nullptr,"patient should be removed");

}

void hospitalTests() {
/**
 * Tests for the Hospital class. (20 points)
 * - Add doctors to the hospital.
 * - Add patients to doctors.
 * - Generate a doctor report and assert it contains the correct details.
 * - Calculate the total number of patients and assert the correct value.
 */

	Hospital civil;
	unique_ptr<Doctor> doctorBhavin(new Doctor("bhavin","D01"));
	unique_ptr<Doctor> doctorDev(new Doctor("dev","D02"));
	std::unique_ptr<Patient> rutvik(new Patient("rutvik","P01",23));
	std::unique_ptr<Patient> rutviknoBhai(new Patient("hutvik","P02",20));
	std::unique_ptr<Patient> apurva(new Patient("apurva","P03",27));


	civil.addDoctor(move(doctorBhavin));
	civil.addDoctor(move(doctorDev));
	civil.findDoctorById("D01")->addPatient(move(rutvik));
	civil.findDoctorById("D02")->addPatient(move(rutviknoBhai));
	civil.findDoctorById("D02")->addPatient(move(apurva));

	cout<<civil.generateDoctorReport();
	assertTrue(civil.calculateTotalPatients()==3,"total no of patients are not correct");
}

void administratorTests() {
/**
 * Tests for the Administrator class. (10 points)
 * - Add doctors and patients via the administrator.
 * - Remove patients via the administrator.
 */
	Hospital civil;
	unique_ptr<Doctor> doctorBhavin(new Doctor("bhavin","D01"));
	unique_ptr<Doctor> doctorDev(new Doctor("dev","D02"));
	std::unique_ptr<Patient> rutvik(new Patient("rutvik","P01",23));
	std::unique_ptr<Patient> rutviknoBhai(new Patient("hutvik","P02",20));
	std::unique_ptr<Patient> apurva(new Patient("apurva","P03",27));


	civil.addDoctor(move(doctorBhavin));
	civil.addDoctor(move(doctorDev));
	civil.findDoctorById("D01")->addPatient(move(rutvik));
	civil.findDoctorById("D02")->addPatient(move(rutviknoBhai));
	civil.findDoctorById("D02")->addPatient(move(apurva));
	Administrator admin1("admin",civil);
	admin1.removePatientFromDoctor("D02","P03");
	cout<<civil.generateDoctorReport();
	admin1.addPatientToDoctor("D01","apurva","P03",27);
	cout<<civil.generateDoctorReport();
	admin1.addDoctorToHospital("anton","D03");
	cout<<civil.generateDoctorReport();


}

void appointmentTests() {
/**
 * Tests for the Appointment class. (15 points)
 * - Create an Appointment instance.
 * - Assert the getters return the expected values.
 * - Reschedule the appointment and assert the new date.
 */
	unique_ptr<Doctor> doctorBhavin(new Doctor("bhavin","D01"));
	std::unique_ptr<Patient> rutvik(new Patient("rutvik","P01",23));

	Appointment app(rutvik.get(),doctorBhavin.get(),Poco::DateTime(2024,8,2));
	assertTrue(app.getAppointmentDate()==Poco::DateTime(2024,8,2),"getter not correct");
	app.reschedule(Poco::DateTime(2024,8,3));
	assertTrue(app.getAppointmentDate()==Poco::DateTime(2024,8,3),"getter not correct");


}

void exceptionHandleTests() {
/**
 * Tests for exception handling. (5 points)
 * - Attempt to add a patient to a non-existent doctor and catch the exception.
 * - Attempt to remove a non-existent patient and catch the exception.
 */
	Hospital civil;
	unique_ptr<Doctor> doctorBhavin(new Doctor("bhavin","D01"));
	unique_ptr<Doctor> doctorDev(new Doctor("dev","D02"));
	std::unique_ptr<Patient> rutvik(new Patient("rutvik","P01",23));
	std::unique_ptr<Patient> rutviknoBhai(new Patient("hutvik","P02",20));
	std::unique_ptr<Patient> apurva(new Patient("apurva","P03",27));


	civil.addDoctor(move(doctorBhavin));
	civil.addDoctor(move(doctorDev));
	civil.findDoctorById("D01")->addPatient(move(rutvik));
	civil.findDoctorById("D02")->addPatient(move(rutviknoBhai));
	civil.findDoctorById("D02")->addPatient(move(apurva));

	Administrator admin1("admin",civil);
	try{
	admin1.addPatientToDoctor("XYZ","Lea","Pxx",23);
	assertTrue(false,"exception does not occur");
	}catch( std::exception& e){
		cout<<e.what()<<endl;
	}

	try{
		admin1.removePatientFromDoctor("D01","nonexist");
		assertTrue(false,"exception does not occur");
	}catch( std::exception& e){
		cout<<e.what()<<endl;

	}

}

void allTests() {
    patientTests();
    doctorTests();
    hospitalTests();
    administratorTests();
    appointmentTests();
    exceptionHandleTests();
}

