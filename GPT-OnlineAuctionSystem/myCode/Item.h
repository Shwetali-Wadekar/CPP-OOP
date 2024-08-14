/*
 * Item.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef ITEM_H_
#define ITEM_H_


#include <string>
#include <memory>
#include <Poco/JSON/Object.h>

/**
 * Base class for items in the auction system. (10 points)
 */
class Item {
protected:
    std::string itemId;
    std::string name;
    std::string description;
    double startingPrice;

public:
    /**
     * Initializes a new item with the given details. (3 points)
     *
     * @param itemId The unique identifier for the item
     * @param name The name of the item
     * @param description A description of the item
     * @param startingPrice The starting price of the item
     */
    Item(const std::string& itemId, const std::string& name, const std::string& description, double startingPrice);

    /**
     * Pure virtual method to return item type. (2 points)
     *
     * @return The item type
     */
    virtual std::string getItemType() const = 0;

    /**
     * Returns the item ID. (1 point)
     *
     * @return The item ID
     */
    std::string getItemId() const;

    /**
     * Displays item information. (3 points)
     */
    virtual void displayInfo() const;

    /**
     * Converts the item details to a JSON object. (3 points)
     *
     * @return A JSON object with item details
     */
    virtual std::shared_ptr<Poco::JSON::Object> toJson() const;

    /**
     * Returns the starting price of the item. (1 point)
     *
     * @return The starting price
     */
    double getStartingPrice() const;
};


#endif /* ITEM_H_ */
