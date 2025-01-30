#include "Doctor.h"
#include "HealthcareException.h"
Doctor::Doctor(const std::string &name, const std::string &doctorId) :
		name(name), doctorId(doctorId)
{
}

std::string Doctor::getName() const
{
	return this->name;
}

std::string Doctor::getDoctorId() const
{
	return this->doctorId;
}

void Doctor::addPatient(std::unique_ptr<Patient> patient)
{
	patients.push_back(std::move(patient));

}

void Doctor::removePatient(const std::string &patientId)
{
	for (auto iter = patients.begin(); iter != patients.end(); iter++)
	{
		if (patientId == (*iter)->getPatientId())
		{
			iter = patients.erase(iter);
			return;
		}
	}
	throw HealthcareException("Patient not found");
}

Patient* Doctor::findPatientById(const std::string &patientId)
{
	for (auto &patient : patients)
	{
		if (patientId == patient->getPatientId())
		{
			return patient.get();
		}
	}
	return nullptr;
	throw HealthcareException("Patient not found");
}

std::vector<Patient*> Doctor::allPatients()
{
	std::vector<Patient*> allpatients;
	for (auto &patient:patients){
		allpatients.push_back(patient.get());
	}
 return allpatients;
}
