#ifndef APPOINTMENT_H_
#define APPOINTMENT_H_

#include <string>
#include <Poco/DateTime.h>
#include "Patient.h"
#include "Doctor.h"

/**
 * Represents an appointment in the healthcare management system.
 */
class Appointment {
private:
    Patient* patient;
    Doctor* doctor;
    Poco::DateTime appointmentDate;

public:
    /**
     * Initializes a new appointment with the given patient, doctor, and date.
     *
     * @param patient the patient for the appointment
     * @param doctor the doctor for the appointment
     * @param appointmentDate the date of the appointment
     */
    Appointment(Patient* patient, Doctor* doctor, const Poco::DateTime& appointmentDate);

    /**
     * Returns the patient for the appointment.
     *
     * @return the patient
     */
    Patient* getPatient() const;

    /**
     * Returns the doctor for the appointment.
     *
     * @return the doctor
     */
    Doctor* getDoctor() const;

    /**
     * Returns the date of the appointment.
     *
     * @return the appointment date
     */
    Poco::DateTime getAppointmentDate() const;

    /**
     * Reschedules the appointment to a new date.
     *
     * @param newDate the new appointment date
     */
    void reschedule(const Poco::DateTime& newDate);
};

#endif /* APPOINTMENT_H_ */
