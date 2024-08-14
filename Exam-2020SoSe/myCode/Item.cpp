/*
 * Item.cpp
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#include "Item.h"
using namespace std;
#include"Food.h"
Item::Item(std::string name, std::string shop, std::time_t until) : name(name), shop(shop) , until(until)
{
}

std::string Item::getName() const
{
	return name;
}

std::string Item::getShop() const
{
	return shop;
}

std::time_t Item::getUntil() const
{
	return until;
}

std::string Item::toString() const
{
	return name+" ("+shop+")";
}

std::set<std::string> Item::getNotes() const
{
	return set<string>();


}

Item::~Item()
{
	// TODO Auto-generated destructor stub
}
//* Example: Item;Soap;Drug store;6597989

void Item::save(std::ostream &to) const
{
	to<<"Item;"<<name+";"+shop+";"+std::to_string(until)<<endl;
}

Item* Item::restore(std::string line)
{
	extern string splitAt(string& remainder, char separator);
	string type;
	type=splitAt(line,';');
	if(type=="Item") {
		string itemname=splitAt(line,';');
		string shopname=splitAt(line,';');
		string untiltime=splitAt(line,';');

		Item* itemptr= new Item(itemname,shopname,std::stol(untiltime));
		return itemptr;

	}else {
		return nullptr;
	}
}
