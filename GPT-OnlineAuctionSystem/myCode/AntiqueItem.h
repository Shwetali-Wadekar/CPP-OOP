/*
 * AntiqueItem.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef ANTIQUEITEM_H_
#define ANTIQUEITEM_H_

#include "Item.h"


/**
 * Represents an antique item. (5 points)
 */
class AntiqueItem : public Item {
	std::string itemType="AntiqueItem";
public:
    /**
     * Initializes a new antique item with the given details. (2 points)
     *
     * @param itemId The unique identifier for the item
     * @param name The name of the item
     * @param description A description of the item
     * @param startingPrice The starting price of the item
     */
    AntiqueItem(const std::string& itemId, const std::string& name, const std::string& description, double startingPrice);

    /**
     * Returns the item type. (1 point)
     *
     * @return The item type
     */
    std::string getItemType() const override;

    /**
     * Displays antique item information. (2 points)
     */
    void displayInfo() const override;
};
#endif /* ANTIQUEITEM_H_ */
