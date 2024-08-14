#ifndef HEALTHCAREEXCEPTION_H_
#define HEALTHCAREEXCEPTION_H_

#include <stdexcept>
#include <string>

/**
 * Represents exceptions specific to the healthcare management system.
 */
class HealthcareException : public std::runtime_error {
public:
    HealthcareException(const std::string& message);
};

#endif /* HEALTHCAREEXCEPTION_H_ */
