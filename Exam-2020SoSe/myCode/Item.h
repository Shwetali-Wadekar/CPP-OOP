/*
 * Item.h
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <ctime>
#include <string>
#include <set>
#include <ostream>

class Item
{
private:
	std::string name;
	std::string shop;
	std::time_t until;

public:
	Item(std::string name, std::string shop, std::time_t until);
	//Item();
	std::string getName() const;
	std::string getShop() const;
	std::time_t getUntil() const;

	/**
	 * Special kinds of items (see class Food) may require one or more
	 * notes to be appended to the shopping list. This function returns
	 * the notes required by an item.
	 */
	virtual std::set<std::string> getNotes() const;
	/**
	 * Returns a string with the name of the item followed by the shop
	 * in parenthesis.
	 */
	virtual std::string toString() const;
	/**
	 * Writes to the given ostream the string "Item;" and then
	 * all attributes separated by semicolon and a final newline.
	 * Example: Item;Soap;Drug store;6597989
	 */
	virtual void save(std::ostream& to) const;

	/**
	 * Creates a new instance on the heap, using the values from
	 * the given string. The string must have the format used by
	 * method save. If the string does not start with "Item;", a
	 * nullptr is returned. (Use function splitAt in main for the
	 * implementation.)
	 */
	static Item* restore(std::string line);

	virtual ~Item();

};

#endif /* ITEM_H_ */
