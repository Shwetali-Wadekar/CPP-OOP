#ifndef ORDER_H
#define ORDER_H

#include "Item.h"
#include <list>
#include <memory>
#include <exception>

/**
 * Represents an order containing a list of items.
 */
class Order {
private:
    std::list<std::unique_ptr<Item>> orderItems;

public:
    /**
     * Adds an item to the order.
     *
     * @param item a unique pointer to the item to add.
     */
    void addItem(std::unique_ptr<Item> item);

    /**
     * Removes an item from the order by name.
     *
     * @param name the name of the item to remove.
     * @throws std::runtime_error if the item is not found.
     */
    void removeItem(const std::string& name);

    /**
     * Gets the total quantity of items in the order.
     *
     * @return the total quantity.
     */
    float getTotalQuantity() const;
};

#endif // ORDER_H
