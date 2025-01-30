
#include "Appointment.h"

Appointment::Appointment(Patient *patient, Doctor *doctor,
		const Poco::DateTime &appointmentDate) : patient(patient) , doctor(doctor) , appointmentDate(appointmentDate)
{
}

Patient* Appointment::getPatient() const
{
	return this->patient;
}

Doctor* Appointment::getDoctor() const
{
	return this->doctor;
}

Poco::DateTime Appointment::getAppointmentDate() const
{
	return this->appointmentDate;
}

void Appointment::reschedule(const Poco::DateTime &newDate)
{
	this->appointmentDate=newDate;
}
