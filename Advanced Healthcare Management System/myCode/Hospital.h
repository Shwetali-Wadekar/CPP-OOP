#ifndef HOSPITAL_H_
#define HOSPITAL_H_

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "Doctor.h"

/**
 * Represents a hospital with multiple doctors.
 */
class Hospital {
private:
    std::vector<std::unique_ptr<Doctor>> doctors;

public:
    /**
     * Adds a doctor to the hospital.
     *
     * @param doctor the doctor to add
     */
    void addDoctor(std::unique_ptr<Doctor> doctor);

    /**
     * Finds a doctor by their ID.
     *
     * @param doctorId the doctor's ID
     * @return a pointer to the doctor if found, nullptr otherwise
     */
    Doctor* findDoctorById(const std::string& doctorId);

    /**
     * Generates a report of all doctors and their patients.
     *
     * @return a string containing the report
     */
    std::string generateDoctorReport() const;

    /**
     * Calculates the total number of patients in the hospital.
     *
     * @return the total number of patients
     */
    int calculateTotalPatients() const;
};

#endif /* HOSPITAL_H_ */
