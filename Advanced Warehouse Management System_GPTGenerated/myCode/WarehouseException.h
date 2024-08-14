#ifndef WAREHOUSEEXCEPTION_H_
#define WAREHOUSEEXCEPTION_H_

#include <stdexcept>
#include <string>

/**
 * Represents exceptions specific to the warehouse management system.
 */
class WarehouseException : public std::runtime_error {
public:
    WarehouseException(const std::string& message) : std::runtime_error(message) {}
};

#endif /* WAREHOUSEEXCEPTION_H_ */
