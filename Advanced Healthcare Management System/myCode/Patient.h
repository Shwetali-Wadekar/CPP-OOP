#ifndef PATIENT_H_
#define PATIENT_H_

#include <string>

/**
 * Represents a patient in the healthcare management system.
 */
class Patient {
private:
    std::string name;
    std::string patientId;
    int age;

public:
    /**
     * Initializes a new patient with the given name, ID, and age.
     *
     * @param name the patient's name
     * @param patientId the patient's ID
     * @param age the patient's age
     */
    Patient(const std::string& name, const std::string& patientId, int age);

    /**
     * Returns the patient's name.
     *
     * @return the patient's name
     */
    std::string getName() const;

    /**
     * Returns the patient's ID.
     *
     * @return the patient's ID
     */
    std::string getPatientId() const;

    /**
     * Returns the patient's age.
     *
     * @return the patient's age
     */
    int getAge() const;

    /**
     * Sets the patient's age.
     *
     * @param age the new age
     */
    void setAge(int age);
};

#endif /* PATIENT_H_ */
