#ifndef EXCEPTIONHANDLING_H
#define EXCEPTIONHANDLING_H

#include <stdexcept>
#include <string>

/**
 * Custom exception for handling order processing errors.
 */
class OrderProcessingException : public std::runtime_error {
public:
    /**
     * Constructs a new OrderProcessingException with the given message.
     *
     * @param message the exception message.
     */
    explicit OrderProcessingException(const std::string& message);
};

#endif // EXCEPTIONHANDLING_H
