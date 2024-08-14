#ifndef COMPANYEXCEPTION_H_
#define COMPANYEXCEPTION_H_

#include <stdexcept>
#include <string>

/**
 * Represents exceptions specific to the company management system.
 */
class CompanyException : public std::runtime_error {
public:
    CompanyException(const std::string& message);
};

#endif /* COMPANYEXCEPTION_H_ */
