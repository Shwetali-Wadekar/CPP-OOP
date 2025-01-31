#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <stdexcept>
#include <map>
#include "Product.h"
#include "Warehouse.h"
#include "InventoryManager.h"
#include "WarehouseManager.h"
#include "DiscountAdjuster.h"
#include "WarehouseException.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, const string& failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

void productTests() {
/**
 * Tests for the Product class. (10 points)
 * - Create a Product instance.
 * - Assert the getters return the expected values.
 * - Change the price and assert the new value.
 */

	Product p("milk","m1",1.29);
	assertTrue((p.getPrice()-1.29)<0.00001,"price getter wrong");
	assertTrue(p.getName()=="milk","name getter wrong");
	p.setPrice(0.99);
	assertTrue((p.getPrice()-0.99)<0.00001,"price getter wrong");



}

void warehouseTests() {
/**
 * Tests for the Warehouse class. (10 points)
 * - Create a Warehouse instance.
 * - Add products to the warehouse and assert they are added correctly.
 * - Remove products by ID and assert they are removed correctly.
 * - Find products by ID and assert the correct product is returned.
 */
	Product* milk=new Product("milk","1",0.99);
	Product* tortilla=new Product("tortila","2",1.29);


	Warehouse picnic("picnic");
	picnic.addProduct(std::unique_ptr<Product>(milk));
	picnic.addProduct(std::unique_ptr<Product>(tortilla));

	set<std::string> expected={"1","2"};


	auto allproducts=picnic.allproducts();
	for(auto iter = allproducts.begin() ; iter != allproducts.end() ; ++iter) {
		assertTrue(expected.find((*iter)->getProductId())!=expected.end(),"product does not exist");
	}

}

void inventoryManagerTests() {
/**
 * Tests for the InventoryManager class. (20 points)
 * - Add warehouses to the inventory manager.
 * - Add products to warehouses.
 * - Generate a product report and assert it contains the correct details.
 * - Calculate the total value of all products and assert the correct value.
 */


	InventoryManager im;
	std::unique_ptr<Warehouse> warehouse(new Warehouse("Picnic"));
	im.addWarehouse(move(warehouse));

	Product* milk=new Product("milk","1",0.99);
	Product* tortilla=new Product("tortila","2",1.29);

	im.findWarehouseByName("Picnic")->addProduct(std::unique_ptr<Product>(milk));
	im.findWarehouseByName("Picnic")->addProduct(std::unique_ptr<Product>(tortilla));

	cout<<im.generateProductReport();

	cout<<im.calculateTotalValue();




}

void warehouseManagerTests() {
/**
 * Tests for the WarehouseManager class. (10 points)
 * - Add warehouses and products via the warehouse manager.
 * - Remove products via the warehouse manager.
 */
	InventoryManager im;
	std::unique_ptr<Warehouse> warehouse(new Warehouse("Picnic"));
	im.addWarehouse(move(warehouse));

	Product* milk=new Product("milk","1",0.99);
	Product* tortilla=new Product("tortila","2",1.29);

	im.findWarehouseByName("Picnic")->addProduct(std::unique_ptr<Product>(milk));
	im.findWarehouseByName("Picnic")->addProduct(std::unique_ptr<Product>(tortilla));

	WarehouseManager manager("bhavin",im);
	manager.addProductToWarehouse("Picnic","oats","3",0.29);
	cout<<im.generateProductReport();

	manager.removeProductFromWarehouse("Picnic","2");
	cout<<im.generateProductReport();

}

void discountAdjusterTests() {
/**
 * Tests for the DiscountAdjuster class. (15 points)
 * - Add discounts for products.
 * - Adjust product prices based on the discounts and assert the correct adjusted prices.
 */

	DiscountAdjuster da;
	const Product milk("milk","1",0.99);
	const Product totilla("tortila","2",1.29);
	da.addDiscount("1",0.1);
	da.addDiscount("2",0.2);
	da.addDiscount("3",0.3);
	cout<<da.adjust(milk);

}

void exceptionHandleTests() {
/**
 * Tests for exception handling. (5 points)
 * - Attempt to remove a product from a non-existent warehouse and catch the exception.
 * - Attempt to perform operations on non-existent products or warehouses and catch the exception.
 */
}

void allTests() {
    productTests();
    warehouseTests();
    inventoryManagerTests();
    warehouseManagerTests();
    discountAdjusterTests();
    exceptionHandleTests();
}

