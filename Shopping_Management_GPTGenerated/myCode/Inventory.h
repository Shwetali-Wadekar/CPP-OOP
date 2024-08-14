#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <map>
#include <string>

/**
 * Represents an inventory of items with their stock quantities.
 */
class Inventory {
private:
    std::map<std::string, float> stock;

public:
    /**
     * Adds stock for an item.
     *
     * @param name the name of the item.
     * @param quantity the quantity to add.
     */
    void addStock(const std::string& name, float quantity);

    /**
     * Removes stock for an item.
     *
     * @param name the name of the item.
     * @param quantity the quantity to remove.
     * @throws std::runtime_error if the item is not found or insufficient stock.
     */
    void removeStock(const std::string& name, float quantity);

    /**
     * Gets the stock quantity for an item.
     *
     * @param name the name of the item.
     * @return the stock quantity.
     * @throws std::runtime_error if the item is not found.
     */
    float getStock(const std::string& name) const;
};

#endif // INVENTORY_H
