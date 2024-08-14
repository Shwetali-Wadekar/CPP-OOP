/*
 * Administrator.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "Administrator.h"
#include "HealthcareException.h"
using namespace std;
Administrator::Administrator(const std::string &name, Hospital &hospital) : name(name) , hospital(hospital)
{
}

std::string Administrator::getName() const
{
	return this->name;
}

void Administrator::addDoctorToHospital(const std::string &doctorName,
		const std::string &doctorId)
{
	unique_ptr<Doctor> doctor(new Doctor(doctorName,doctorId));
	hospital.addDoctor(move(doctor));
}

void Administrator::addPatientToDoctor(const std::string &doctorId,
		const std::string &patientName, const std::string &patientId, int age)
{
	auto doctor=hospital.findDoctorById(doctorId);
	if(doctor != nullptr) {
		unique_ptr<Patient> patient(new Patient(patientName,patientId,age));
		doctor->addPatient(move(patient));

	}else {
		throw HealthcareException("Doctor does not exist");
	}
}

void Administrator::removePatientFromDoctor(const std::string &doctorId,
		const std::string &patientId)
{
	auto doctor=hospital.findDoctorById(doctorId);
	if(doctor != nullptr) {

		doctor->removePatient(patientId);

	}else {
		throw HealthcareException("Doctor does not exist");
	}
}
