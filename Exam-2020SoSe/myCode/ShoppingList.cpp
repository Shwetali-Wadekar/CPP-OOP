/*
 * ShoppingList.cpp
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#include "ShoppingList.h"
#include<iostream>
#include<set>
using namespace std;

ShoppingList& ShoppingList::operator +=(Item *item)
		{

	items[item->getShop()].push_back(std::move(std::unique_ptr<Item>(item)));
	return *this;

		}
/**
 * Print all items from the shopping list which must be bought
 * until the given time. The output is grouped by shops. At the
 * end of the output all collected notes from the items are
 * printed. Identical notes are printed only once. Example:
 *
 * Shopping List:
 * * Butcher:
 * - Steak (Butcher) [Keep cool!]
 *
 * * Drug store:
 *
 * * Super market:
 * - Milk (Super market) [Keep cool!]
 * - Rice (Super market)
 *
 * Notes:
 * [1] One or more items require cooling!
 */
void ShoppingList::print(std::time_t until) const
{
	set<string> notes;
	cout<<endl<<"Shopping List:"<<endl;


	for(auto i=items.begin() ; i != items.end() ; ++i) {

		cout<<"* "<<i->first+":"<<endl;

		//auto shopitems= i->second;
		//i->second.begin()
		for(auto itr=i->second.begin() ; itr != i->second.end() ; ++itr) {
			if( (**itr).getUntil()==until) {
				cout<<"- "<<(**itr).toString()<<endl;

				std::set<std::string> notset= (**itr).getNotes();

				//notes.insert((**itr).getNotes());
				for( auto itr2= notset.begin() ; itr2 != notset.end() ; ++itr2) {
					notes.insert(*itr2);
				}

			}
		}
		cout<<endl;



	}
	cout<<"Notes:"<<endl;
	int count=1;
	for( auto i=notes.begin() ; i != notes.end() ; ++i) {
		cout<<"["<<count<<"] "<<*i<<endl;
		count++;
	}

}

void ShoppingList::save(std::ostream &to) const
{
	for(auto i=items.begin() ; i != items.end() ; ++i) {

		for(auto iter=(*i).second.begin() ; iter != (*i).second.end() ; ++iter) {
			(**iter).save(to);
		}

	}
}

void ShoppingList::load(std::istream &from)
{
	string line;
	while(getline(from,line)) {
		if( Item::restore(line) != nullptr) {
			Item* item= Item::restore(line);
			items[item->getShop()].push_back(std::move(std::unique_ptr<Item>(item)));
		}else if ( Food::restore(line) != nullptr) {
			Food* item= Food::restore(line);
			items[item->getShop()].push_back(std::move(std::unique_ptr<Food>(item)));
		}
	}
}
