#ifndef DOCTOR_H_
#define DOCTOR_H_

#include <string>
#include <vector>
#include <memory>
#include "Patient.h"

/**
 * Represents a doctor in the healthcare management system.
 */
class Doctor {
private:
    std::string name;
    std::string doctorId;
    std::vector<std::unique_ptr<Patient>> patients;

public:
    /**
     * Initializes a new doctor with the given name and ID.
     *
     * @param name the doctor's name
     * @param doctorId the doctor's ID
     */
    Doctor(const std::string& name, const std::string& doctorId);

    /**
     * Returns the doctor's name.
     *
     * @return the doctor's name
     */
    std::string getName() const;

    /**
     * Returns the doctor's ID.
     *
     * @return the doctor's ID
     */
    std::string getDoctorId() const;

    /**
     * Adds a patient to the doctor's list of patients.
     *
     * @param patient the patient to add
     */
    void addPatient(std::unique_ptr<Patient> patient);

    /**
     * Removes a patient from the doctor's list by ID.
     *
     * @param patientId the patient's ID
     * @throws std::invalid_argument if the patient is not found
     */
    void removePatient(const std::string& patientId);

    /**
     * Finds a patient by their ID.
     *
     * @param patientId the patient's ID
     * @return a pointer to the patient if found, nullptr otherwise
     */
    Patient* findPatientById(const std::string& patientId);

    std::vector<Patient*> allPatients();

};

#endif /* DOCTOR_H_ */
