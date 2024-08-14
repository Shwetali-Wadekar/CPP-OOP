#ifndef DEVICEEXCEPTION_H_
#define DEVICEEXCEPTION_H_

#include <exception>
#include <string>

/**
 * Exception thrown when there is an error with a device.
 */
class DeviceException : public std::exception {
private:
    std::string message;

public:
    /**
     * Creates a new DeviceException with the given message.
     *
     * @param message the exception message
     */
    DeviceException(const std::string& message);

    /**
     * Gets the exception message.
     *
     * @return the message
     */
    const char* what() const noexcept override;
};

#endif /* DEVICEEXCEPTION_H_ */
