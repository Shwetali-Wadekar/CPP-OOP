#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "Customer.h"
#include <map>
#include <memory>

/**
 * Manages a collection of customers using a map.
 */
class CustomerManager {
private:
    std::map<std::string, std::unique_ptr<Customer>> customerMap;

public:
    /**
     * Adds a customer to the manager.
     *
     * @param customer a unique pointer to the customer to add.
     */
    void addCustomer(std::unique_ptr<Customer> customer);

    /**
     * Gets a customer by name.
     *
     * @param name the name of the customer.
     * @return a pointer to the customer.
     * @throws std::runtime_error if the customer is not found.
     */
    Customer* getCustomer(const std::string& name) const;
};

#endif // CUSTOMERMANAGER_H
