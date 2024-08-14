#ifndef RETURNEXCEPTION_H_
#define RETURNEXCEPTION_H_

#include <exception>
#include <string>

/**
 * Exception thrown when a book cannot be returned.
 */
class ReturnException : public std::exception {
private:
    std::string message;

public:
    ReturnException(const std::string& message);

    const char* what() const noexcept override;
};

#endif /* RETURNEXCEPTION_H_ */
