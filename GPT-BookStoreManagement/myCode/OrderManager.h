/*
 * OrderManager.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef ORDERMANAGER_H_
#define ORDERMANAGER_H_


#include "Order.h"

/**
 * Manages all customer orders. (20 points)
 */
class OrderManager {
private:
    map<string, unique_ptr<Order>> orders;

public:
    /**
     * Adds a new order to the system. If an order with the same ID already exists,
     * throws an exception. (5 points)
     *
     * @param order the order to add
     * @throws std::runtime_error
     */
    void addOrder(unique_ptr<Order> order);

    /**
     * Removes an order from the system by its ID. If no such order exists, does nothing. (3 points)
     *
     * @param orderId the ID of the order to remove
     */
    void removeOrder(const string& orderId);

    /**
     * Searches for an order by its ID and returns a pointer to it.
     * If no such order exists, returns nullptr. (3 points)
     *
     * @param orderId the ID to search for
     * @return a pointer to the order, or nullptr if not found
     */
    Order* searchByOrderId(const string& orderId) const;

    /**
     * Returns all orders sorted by order date. (4 points)
     *
     * @return a vector of pointers to all orders sorted by date
     */
    vector<Order*> getAllOrdersSortedByDate() const;
};

#endif /* ORDERMANAGER_H_ */
