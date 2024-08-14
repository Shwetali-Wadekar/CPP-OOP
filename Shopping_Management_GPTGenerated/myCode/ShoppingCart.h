#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Item.h"
#include <vector>
#include <memory>

/**
 * Represents a shopping cart containing multiple items.
 */
class ShoppingCart {
private:
    std::vector<std::unique_ptr<Item>> items;

public:
    /**
     * Adds an item to the shopping cart.
     *
     * @param item a unique pointer to the item to add.
     */
    void addItem(std::unique_ptr<Item> item);

    /**
     * Removes an item from the shopping cart by name.
     *
     * @param name the name of the item to remove.
     * @throws std::runtime_error if the item is not found.
     */
    void removeItem(const std::string& name);

    /**
     * Gets the total quantity of items in the shopping cart.
     *
     * @return the total quantity.
     */
    float getTotalQuantity() const;
};

#endif // SHOPPINGCART_H
