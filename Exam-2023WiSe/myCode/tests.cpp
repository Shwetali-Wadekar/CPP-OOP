#include <iostream>
#include <cstdlib>
#include <memory>
#include <set>
#include <cmath>
#include <stdexcept>
#include <algorithm>

#include "FixedDiscount.h"
#include "ShoppingList.h"
#include "ShopDb.h"
#include "Shop.h"
#include "Item.h"
#include "QuantityDiscount.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the shopping list classes. (XX points)
 */
void shoppingListTests() {
	/*
	 * Create a shopping list with 2 (l) of milk, 250 (g) butter,
	 * and 1.5 (kg) bread. Use ShoppingList::items to retrieve
	 * the items and assert that for each that they have the
	 * expected name and quantity. (12 points)
	 */
	// TODO
	ShoppingList mylist;
	mylist.addItem("milk",2).addItem("butter",250).addItem("bread",1.5);

	std::list<Item>::const_iterator begin;
	std::list<Item>::const_iterator end;

	mylist.items(begin,end);
	vector<string> actualItemName;
	vector<string> expectedItemName={"milk","butter","bread"};
	vector<float> expectedItemQty={2,250,1.5};
	vector<float> actualItemQty;//={2,250,1.5};

	for( auto i=begin ; i != end ; ++i ) {
		actualItemName.push_back(i->getName());
		actualItemQty.push_back(i->getQuantity());
	}

	for( size_t i=0 ; i<expectedItemName.size() ; i++) {

		assertTrue(actualItemName[i]==expectedItemName[i], "name does not matched");
		assertTrue(expectedItemQty[i]==actualItemQty[i], "qty does not matched");

	}



}

/**
 * Tests for the shop db classes. (XX points)
 */
void shopDbTests() {
    /*
     * (1) Test the methods of class ShopDb using the names given below.
     * Proceed as follows:
     *   * Create a ShopDb and add shops with the given names to it.
     *   * Use ShopDb::shops to get pointers to the shops in the database.
     *   * For each shop,
     *       * assert that that the shop's name is in the set "names".
     *       * assert that that the pointer that you got from ShopDb::shops
     *         is equal to the pointer that you get from ShopDb::shopByName
     *       * remove the shop's name from the set "names".
     *   * Finally assert that that you got all shops by checking that the
     *     set "names" is empty.
     *   (7 points)
     */
	set<string> names = { "Foodie1", "Bakers4less", "Spiceology", "Grainfruit",
		"Sweetteas", "Savorystyle", "TheSpiceHouse", "FoodieFun",
		"FlavorStation", "DoughLife", "INGredientsOnly", "FreshFix", "Tastync",
		"FlavorFile", "BiteMe", "TheFlavorSpot", "AtisfyMyCravings",
		"TastyTreats", "TheFoodFactor", "MunchiesLand", "TheSnackCave",
		"FoodieFrenzy", "TheMorselMansion", "BiteClub", "TheSavorStore",
		"TheFoodieFactor", "FlavorfulFinds", "TheTastyTrove" };

	// TODO
	ShopDb db;


	for( auto i= names.begin() ; i != names.end() ; ++i) {

		db.addShop( move(std::unique_ptr<Shop>(new Shop(*i))));


	}

	std::vector<Shop*> allShops;

	allShops= db.shops();


	for(size_t i=0; i<allShops.size() ; i++) {

		auto checkname=names.find(allShops[i]->getName());
		assertTrue(checkname != names.end() , "shop name does not found" );
		//assertTrue(db.shopByName(allShops.at(i)->getName())==db.shops(),"pointer doesnot same");


	}

	for(auto i=allShops.begin() ; i != allShops.end() ; ++i) {

		auto checkname= names.find((**i).getName());
		assertTrue(checkname != names.end() , "shop name does not found" );
		assertTrue( db.shopByName((**i).getName())== *i,"Pointers do not match" );
		names.erase((**i).getName());


	}


	assertTrue(names.size()==0,"names size not zero");





	/*
	 * (2) Test LinearDiscount by creating an instance for 5% (0.05) and //fixed discunt
	 * another one for 10% (0.1) and then asserting for each of the
	 * two that you get the expected result when invoking
	 * LinearDiscount::discountFor with arguments 0, 10 and 100. (6 points)
	 */
	// TODO

	FixedDiscount fd(0.05);
	FixedDiscount fd1(0.1);

	//cout<<fd.discountFor(0)<<" "<<fd1.discountFor(0);
	float d1=0.05;
	float d2=0.1;


	assertTrue(fd.discountFor(0)==d1, "disocunt not same");
	assertTrue(fd.discountFor(10)==d1, "discount not same");
	assertTrue(fd.discountFor(100)==d1, "discount not same");
	assertTrue(fd1.discountFor(0)==d2, "disocunt not same");
	assertTrue(fd1.discountFor(10)==d2, "discount not same");
	assertTrue(fd1.discountFor(100)==d2, "discount not same");



//fd.


	/*
	 * (3) Test QuantityDiscount by creating an instance for the
	 * following rules:
	 *   * A discount of 5% (0.05) starting with a quantity of 10
	 *   * A discount of 10% (0.1) starting with a quantity of 50
	 *   * A discount of 15% (0.15) starting with a quantity of 100
	 *
	 * Assert that that QuantityDiscount::discountFor returns the expected
	 * values for quantities 0, 9, 10, 11, 49, 50, 51, 99, 100 and 101.
	 * (8 points)
	 */
	// TODO
	QuantityDiscount qd;
	qd.addLimit(10,0.05).addLimit(50,0.1).addLimit(100,0.15);

	//cout<<qd.discountFor(150);
	float dis1=0.05,dis2=0.1,dis3=0.15;


	assertTrue(qd.discountFor(0)==0,"discount incorrect");
	assertTrue(qd.discountFor(9)==0,"discount incorrect");
	assertTrue(qd.discountFor(10)==dis1,"discount incorrect");
	assertTrue(qd.discountFor(11)==dis1,"discount incorrect");
	assertTrue(qd.discountFor(49)==dis1,"discount incorrect");
	assertTrue(qd.discountFor(50)==dis2,"discount incorrect");
	assertTrue(qd.discountFor(51)==dis2,"discount incorrect");
	assertTrue(qd.discountFor(99)==dis2,"discount incorrect");
	assertTrue(qd.discountFor(100)==dis3,"discount incorrect");
	assertTrue(qd.discountFor(101)==dis3,"discount incorrect");








	/*
	 * (4) Create a shop "Bakers4less" that sells bread at
	 * 5.6 per unit (kg). Assert that changing the base price
	 * (price per unit) for milk (!) at Bakers4less throws an
	 * invalid_argument exception (because they don't offer milk)
	 * (5 points)
	 */
	// TODO

	Shop myshop("Bakers4less");
	myshop.addProduct(Product("bread",5.6));
	string exception="product not found";
	string actual;
	try{
	myshop.setBasePrice("milk",10);

	}catch (std::invalid_argument& e) {
		actual=e.what();
	}

	assertTrue(actual==exception,"expection not found");
}

void evalTests() {
	/*
	 * Create a shop db. Add the shop "Bakers4less" from the
	 * function shopDbTests. Add another shop "Foodie1" that
	 * sells "Milk" at 2.1 per unit, "Bread" at 5.8 per unit
	 * and "Butter" at 0.00996 per unit.
	 *
	 * Copy the shopping list from function shoppingListTests.
	 *
	 * (1) Assert that purchasing everything from the shopping
	 * list at Foodie1 costs 15.39 and that they have everything
	 * available.
	 *
	 * (2) Assert that the purchase at Bakers4less amounts to
	 * 8.40 only and that the method reports that the shop does not
	 * provide milk and butter.
	 *
	 * (19 points)
	 */
	// TODO
	ShopDb db;

	std::unique_ptr<Shop> shop1=std::unique_ptr<Shop> (new Shop("Bakers4less"));
	shop1.get()->addProduct(Product("Bread",5.6));

	std::unique_ptr<Shop> shop2=std::unique_ptr<Shop> (new Shop("Foodie1"));
	shop2.get()->addProduct(Product("Bread",5.8)).addProduct(Product("Milk",2.1)).
			addProduct(Product("Butter",0.00996));


	db.addShop(move(shop1)).addShop(move(shop2));
	float foodie1Cost=15.39;
	float Bakers4less=8.40;

	ShoppingList mylist;
		mylist.addItem("Milk",2).addItem("Butter",250).addItem("Bread",1.5);


		std::set<const Item*> shop1notAvailable;
		std::set<const Item*> shop2notAvailable;

		//cout<<db.shopByName("Foodie1")->calculatePurchase(mylist,notAvailable);


		//cout<<endl<<notAvailable.size();
		//cout<<shop1.get()->calculatePurchase(mylist,notAvailable);
		assertTrue(db.shopByName("Foodie1")->calculatePurchase(mylist,shop2notAvailable) == foodie1Cost,
				"Foodie1 cost not matching");

		assertTrue(db.shopByName("Bakers4less")->calculatePurchase(mylist,shop1notAvailable) == Bakers4less,
						"Bakers4less cost not matching");


		//string actual[];
		set<string> expected={"Milk","Butter"};
		for(auto i=shop1notAvailable.begin() ; i != shop1notAvailable.end() ; ++i) {

			assertTrue(expected.find((**i).getName()) != expected.end(),"Milk and butter are not present in"
					"not availbale list");
			cout<<(**i).getName()<<endl;
		}





}

void allTests() {
    shoppingListTests();
    shopDbTests();
    evalTests();
}
