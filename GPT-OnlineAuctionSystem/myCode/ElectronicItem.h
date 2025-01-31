/*
 * ElectronicItem.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef ELECTRONICITEM_H_
#define ELECTRONICITEM_H_

#include "Item.h"


/**
     * Represents an electronic item. (5 points)
     */
class ElectronicItem : public Item {
	std::string itemType="ElectronicItem";

public:
    /**
     * Initializes a new electronic item with the given details. (2 points)
     *
     * @param itemId The unique identifier for the item
     * @param name The name of the item
     * @param description A description of the item
     * @param startingPrice The starting price of the item
     */
    ElectronicItem(const std::string& itemId, const std::string& name, const std::string& description, double startingPrice);

    /**
     * Returns the item type. (1 point)
     *
     * @return The item type
     */
    std::string getItemType() const override;

    /**
     * Displays electronic item information. (2 points)
     */
    void displayInfo() const override;
};

#endif /* ELECTRONICITEM_H_ */
