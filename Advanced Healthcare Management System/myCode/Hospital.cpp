#include "Hospital.h"
#include "HealthcareException.h"
#include <sstream>
using namespace std;

void Hospital::addDoctor(std::unique_ptr<Doctor> doctor)
{
	doctors.push_back(std::move(doctor));

}

Doctor* Hospital::findDoctorById(const std::string &doctorId)
{
	for(auto &doctor:doctors){
		if(doctorId == doctor->getDoctorId()){
			return doctor.get();
		}
	}
	return nullptr;
	throw HealthcareException("Doctor not found");
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
	for (const auto& doctor:doctors){
		patientCount+=doctor->allPatients().size();
	}
	return patientCount;
}
