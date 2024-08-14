#ifndef BORROWEXCEPTION_H_
#define BORROWEXCEPTION_H_

#include <exception>
#include <string>

/**
 * Exception thrown when a book cannot be borrowed.
 */
class BorrowException : public std::exception {
private:
    std::string message;

public:
    BorrowException(const std::string& message);

    const char* what() const noexcept override;
};

#endif /* BORROWEXCEPTION_H_ */
