#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_

#include <string>
#include "Hospital.h"

/**
 * Represents an administrator responsible for managing the hospital.
 */
class Administrator {
private:
    std::string name;
    Hospital& hospital;

public:
    /**
     * Initializes a new administrator with the given name.
     *
     * @param name the administrator's name
     * @param hospital the hospital managed by the administrator
     */
    Administrator(const std::string& name, Hospital& hospital);

    /**
     * Returns the administrator's name.
     *
     * @return the administrator's name
     */
    std::string getName() const;

    /**
     * Adds a doctor to the hospital.
     *
     * @param doctorName the doctor's name
     * @param doctorId the doctor's ID
     */
    void addDoctorToHospital(const std::string& doctorName, const std::string& doctorId);

    /**
     * Adds a patient to a doctor's list.
     *
     * @param doctorId the doctor's ID
     * @param patientName the patient's name
     * @param patientId the patient's ID
     * @param age the patient's age
     */
    void addPatientToDoctor(const std::string& doctorId, const std::string& patientName, const std::string& patientId, int age);

    /**
     * Removes a patient from a doctor's list.
     *
     * @param doctorId the doctor's ID
     * @param patientId the patient's ID
     */
    void removePatientFromDoctor(const std::string& doctorId, const std::string& patientId);
};

#endif /* ADMINISTRATOR_H_ */
