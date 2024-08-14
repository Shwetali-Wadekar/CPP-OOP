/*
 * Hospital.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "Hospital.h"
#include <sstream>
using namespace std;
void Hospital::addDoctor(std::unique_ptr<Doctor> doctor)
{
	doctors.push_back(std::move(doctor));
}

Doctor* Hospital::findDoctorById(const std::string &doctorId)
{
	for(auto iter=doctors.begin() ; iter != doctors.end() ; ++iter) {

		if(doctorId == (*iter)->getDoctorId()) {
			return (*iter).get();
		}
	}
	return nullptr;
}

std::string Hospital::generateDoctorReport() const
{	ostringstream oss;
	for(auto iter=doctors.begin() ; iter != doctors.end() ; ++iter) {
		oss<<(*iter)->getDoctorId()+": "+(*iter)->getName()<<endl<<"Patients: "<<endl;
		auto patients= (*iter)->allPatients();

		for(auto i=patients.begin() ; i != patients.end() ; ++i ) {
			oss<<(*i)->getPatientId()+": "<<(*i)->getName()+", age: "<<(*i)->getAge()<<endl;
		}
	}
	return oss.str();
}

int Hospital::calculateTotalPatients() const
{
	int patientCount=0;
	for(auto iter=doctors.begin() ; iter != doctors.end() ; ++iter) {
		patientCount=patientCount+(*iter)->allPatients().size();
	}
	return patientCount;
}
