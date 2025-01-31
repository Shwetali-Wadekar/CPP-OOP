#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <stdexcept>

#include "Item.h"
#include "ShoppingCart.h"
#include "Inventory.h"
#include "Order.h"
#include "Customer.h"
#include "OrderProcessor.h"
//#include "OrderProcessingException.h"
#include "CustomerManager.h"
#include "Utils.h"

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
 * Tests for the ShoppingCart class.
 *
 * Students should implement the following:
 * - Create a ShoppingCart instance.
 * - Add items with names and quantities.
 * - Retrieve the items and assert that they have the expected names and quantities.
 */
void shoppingCartTests() {
    // TODO: Implement tests for the ShoppingCart class.

	ShoppingCart mycart;
	std::unique_ptr<Item> wraps(new Item("wraps",1.29));
	std::unique_ptr<Item> milk1(new Item("milk",0.99));
	std::unique_ptr<Item> avacordo(new Item("avacordo",1.11));
	std::unique_ptr<Item> milk2(new Item("milk",0.99));
	std::unique_ptr<Item> milk3(new Item("milk",0.99));

	mycart.addItem(std::move(wraps));
	mycart.addItem(std::move(milk1));
	mycart.addItem(std::move(milk2));
	mycart.addItem(std::move(milk3));
	mycart.addItem(std::move(avacordo));


	//cout<<mycart.getTotalQuantity();


}

/**
 * Tests for the Inventory class.
 *
 * Students should implement the following:
 * - Create an Inventory instance.
 * - Add items with names and quantities.
 * - Retrieve the items and assert that they have the expected names and quantities.
 */
void inventoryTests() {
    // TODO: Implement tests for the Inventory class.
	Inventory inventory;
	std::unique_ptr<Item> wraps(new Item("wraps",1.29));
	std::unique_ptr<Item> avacordo(new Item("avacordo",1.11));
	std::unique_ptr<Item> milk(new Item("milk",0.99));

	inventory.addStock(wraps.get()->getName(),100);
	inventory.addStock(avacordo.get()->getName(),100);
	inventory.addStock(milk.get()->getName(),100);

	cout<<inventory.getStock("wraps");
}

/**
 * Tests for the Order class.
 *
 * Students should implement the following:
 * - Create an Order instance.
 * - Add items with names and quantities.
 * - Retrieve the items and assert that they have the expected names and quantities.
 */
void orderTests() {
    // TODO: Implement tests for the Order class.
}

/**
 * Tests for the Customer class.
 *
 * Students should implement the following:
 * - Create a Customer instance with a name.
 * - Create Order instances and add items to them.
 * - Add orders to the Customer instance.
 * - Retrieve the orders and assert that they contain the expected items.
 */
void customerTests() {
    // TODO: Implement tests for the Customer class.
}

/**
 * Tests for the OrderProcessor class.
 *
 * Students should implement the following:
 * - Create an OrderProcessor instance.
 * - Create a Customer instance and add orders to it.
 * - Process the orders using the OrderProcessor instance.
 * - Catch any OrderProcessingException and print the error message.
 * - Assert that the orders were processed correctly.
 */
void orderProcessorTests() {
    // TODO: Implement tests for the OrderProcessor class.
}

/**
 * Tests for the CustomerManager class.
 *
 * Students should implement the following:
 * - Create a CustomerManager instance.
 * - Add Customer instances with names to the CustomerManager.
 * - Retrieve the customers and assert that they have the expected names.
 */
void customerManagerTests() {
    // TODO: Implement tests for the CustomerManager class.

}

/**
 * Tests for utility functions in the Utils class.
 *
 * Students should implement the following:
 * - Utilize utility functions and assert that they return the expected results.
 */
void utilsTests() {
    // TODO: Implement tests for utility functions in the Utils class.
	//cout<<endl<<Utils::toUpperCase("bhavin");
	//cout<<endl<<Utils::isValidFloat("5");
}

/**
 * Main function to run all tests.
 */
void allTests(){
	shoppingCartTests();
	inventoryTests();
	orderTests();
	customerTests();
	orderProcessorTests();
	customerManagerTests();
	utilsTests();
}
