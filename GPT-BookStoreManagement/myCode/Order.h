/*
 * Order.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef ORDER_H_
#define ORDER_H_


#include "ShoppingCart.h"
#include <ctime>

/**
 * Models a customer's order. (20 points)
 */
class Order {
private:
    string orderId;
    vector<Book*> books;
    double totalCost;
    time_t orderDate;

public:
    /**
     * Initializes a new order with the given shopping cart and order ID. (3 points)
     *
     * @param cart the shopping cart
     * @param orderId the unique order ID
     */
    Order(const ShoppingCart& cart, const string& orderId);

    /**
     * Returns the order ID. (1 point)
     *
     * @return the order ID
     */
    string getOrderId() const;

    /**
     * Returns the total cost of the order. (2 points)
     *
     * @return the total cost
     */
    double getTotalCost() const;

    /**
     * Returns the date the order was placed. (2 points)
     *
     * @return the order date
     */
    time_t getOrderDate() const;

    /**
     * Returns a list of all books in the order. (2 points)
     *
     * @return a vector of pointers to books in the order
     */
    vector<Book*> getBooks() const;
};

#endif /* ORDER_H_ */
