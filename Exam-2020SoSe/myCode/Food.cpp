/*
 * Food.cpp
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#include "Food.h"
using namespace std;
Food::Food(std::string name, std::string shop, std::time_t until, bool needsCooling) :
Item( name,  shop,  until), needsCooling(needsCooling)
{
	// TODO Auto-generated constructor stub

}

bool Food::getNeedsCooling() const
{
	return needsCooling;
}

std::set<std::string> Food::getNotes() const
{
	if (!needsCooling) {
	return set<string>();
	}
	set<string> result;
	result.insert("One or more items require cooling!");
	return result;
}

std::string Food::toString() const
{
	if(needsCooling) {
	return Item::toString()+" [Keep cool!]";
	}else {
		return Item::toString();
	}
}

void Food::save(std::ostream &to) const
{
	string cool="false";
	if(this->needsCooling) {
		cool="true";
	}
	to<<"Food;"+getName()+";"+getShop()+";"+std::to_string(getUntil())+";"+cool<<endl;
}

Food* Food::restore(std::string line)
{
	extern string splitAt(string& remainder, char separator);
	string type;
	type=splitAt(line,';');
	if(type=="Food") {
		string foodname=splitAt(line,';');
		string shopname=splitAt(line,';');
		string untiltime=splitAt(line,';');
		string coolstr=splitAt(line,';');
		bool cool=false;
		if(coolstr=="true") {
			cool = true;
		}

		Food* foodptr= new Food(foodname,shopname,std::stol(untiltime),cool);
		return foodptr;

	}else {
		return nullptr;
	}
}
