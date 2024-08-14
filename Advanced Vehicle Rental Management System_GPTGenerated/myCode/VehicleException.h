#ifndef VEHICLEEXCEPTION_H_
#define VEHICLEEXCEPTION_H_

#include <stdexcept>
#include <string>

/**
 * Represents exceptions specific to the vehicle rental system.
 */
class VehicleException : public std::runtime_error {
public:
    VehicleException(const std::string& message);
};

#endif /* VEHICLEEXCEPTION_H_ */
