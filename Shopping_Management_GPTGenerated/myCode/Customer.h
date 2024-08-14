#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <memory>
#include "Order.h"

/**
 * Represents a customer with a list of orders.
 */
class Customer {
private:
    std::string name;
    std::vector<std::unique_ptr<Order>> orders;

public:
    /**
     * Initializes a new customer with the given name.
     *
     * @param name the customer's name.
     */
    Customer(const std::string& name);

    /**
     * Adds an order to the customer's list of orders.
     *
     * @param order a unique pointer to the order to add.
     */
    void addOrder(std::unique_ptr<Order> order);

    /**
     * Gets the customer's name.
     *
     * @return the customer's name.
     */
    std::string getName() const;

    /**
     * Gets the total quantity of all items across all orders.
     *
     * @return the total quantity.
     */
    float getTotalOrderQuantity() const;
};

#endif // CUSTOMER_H
