// Item.h
#ifndef ITEM_H_
#define ITEM_H_

#include <string>

/**
 * Represents an item with a name and a price.
 */
class Item {
private:
    std::string name;
    double price;

public:
    /**
     * Constructs an item with the given name and price.
     *
     * @param name the item's name
     * @param price the item's price
     */
    Item(const std::string& name, double price);

    /**
     * Returns the item's name.
     *
     * @return the item's name
     */
    std::string getName() const;

    /**
     * Returns the item's price.
     *
     * @return the item's price
     */
    double getPrice() const;
};

#endif /* ITEM_H_ */
