
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
	std::unique_ptr<Doctor> doctor (new Doctor(doctorName, doctorId));

	hospital.addDoctor(std::move(doctor));
}

void Administrator::addPatientToDoctor(const std::string &doctorId,
		const std::string &patientName, const std::string &patientId, int age)
{
	if(hospital.findDoctorById(doctorId)){
		std::unique_ptr<Patient> patient (new Patient(patientName,patientId, age));
		hospital.findDoctorById(doctorId)->addPatient(move(patient));
	}
	throw HealthcareException("Doctor not found. \n");

}

void Administrator::removePatientFromDoctor(const std::string &doctorId,
		const std::string &patientId)
{
	if(hospital.findDoctorById(doctorId)){
		hospital.findDoctorById(doctorId)->removePatient(patientId);
	}
	throw HealthcareException("Doctor not found. \n");
}
