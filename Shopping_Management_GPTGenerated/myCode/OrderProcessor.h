#ifndef ORDERPROCESSOR_H
#define ORDERPROCESSOR_H

#include "Customer.h"
#include <vector>
#include <stdexcept>

/**
 * Represents an order processor that handles multiple customers.
 */
class OrderProcessor {
private:
    std::vector<std::unique_ptr<Customer>> customers;

public:
    /**
     * Adds a customer to the order processor.
     *
     * @param customer a unique pointer to the customer to add.
     */
    void addCustomer(std::unique_ptr<Customer> customer);

    /**
     * Processes all orders for a customer by name.
     *
     * @param name the name of the customer.
     * @throws std::runtime_error if the customer is not found.
     */
    void processOrders(const std::string& name);

    /**
     * Gets the total quantity of all items across all customers.
     *
     * @return the total quantity.
     */
    float getTotalQuantity() const;
};

#endif // ORDERPROCESSOR_H
