/*
 * Doctor.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "Doctor.h"
#include "HealthcareException.h"
Doctor::Doctor(const std::string &name, const std::string &doctorId) : name(name) , doctorId(doctorId)
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
{	auto foundIter=patients.begin();
	bool flag=false;
	for(auto iter = patients.begin() ; iter != patients.end() ; ++iter) {

		if(patientId==(*iter)->getPatientId()) {
			flag=true;
			foundIter=iter;
		}

	}
	if(flag){
	patients.erase(foundIter);

	}else {
		throw HealthcareException("patient does not exist");
	}
}

Patient* Doctor::findPatientById(const std::string &patientId)
{
	for(auto iter = patients.begin() ; iter != patients.end() ; ++iter) {

		if(patientId==(*iter)->getPatientId()) {

			return (*iter).get();
		}

	}
	return nullptr;

}

std::vector<Patient*> Doctor::allPatients()
{
	std::vector<Patient*> docAllPatients;

	for(auto iter = patients.begin() ; iter != patients.end() ; ++iter) {
		docAllPatients.push_back((*iter).get());
	}


	return docAllPatients;
}
