/*
 * tests.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */


#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "User.h"
#include "Item.h"
#include "Auction.h"
#include "Bid.h"
#include "Buyer.h"
#include "Seller.h"
#include "AuctionManager.h"
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Stringifier.h>
#include "AntiqueItem.h"
#include "ElectronicItem.h"
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

// Test cases for User class
void testUser() {
    // Test constructor and getters
    // 1. Create a Buyer object with specific attributes.

	Buyer bhavin("123","bhavin","prajapti@gmail.com",10000);


    // 2. Verify that the attributes (userId, balance) are correctly set.
	assertTrue(bhavin.getUserId()=="123","id getter incorrect");
	assertTrue(bhavin.getBalance()==10000,"balance getter incorrect");

    // Test balance update
    // 1. Update the balance by a certain amount (e.g., decrease).
	bhavin.updateBalance(900);

    // 2. Verify that the balance is updated correctly.
	assertTrue(bhavin.getBalance()==900,"update balnce is incorrect");

    // Test pure virtual method
    // 1. Verify that the overridden method (getUserRole) returns the expected result for a Buyer.

    // Test displayInfo (requires visual verification)
    // 1. Call displayInfo and visually verify the output for correctness.
	bhavin.displayInfo();

    // Test JSON conversion
    // 1. Convert the User object to JSON.
    // 2. Verify that the JSON contains expected fields (e.g., userId).
	auto poco= bhavin.toJson();
	assertTrue(poco->getValue<string>("Id")=="123","poco object is wrong");
}

// Test cases for Item class
void testItem() {
    // Test constructor and getters
    // 1. Create an Item object (e.g., AntiqueItem) with specific attributes.
	std::shared_ptr<Item> item1(new AntiqueItem("AI1","table","IKEA Table with variable hight",150));
	std::shared_ptr<Item> item2(new ElectronicItem("EI1","laptop","HP gaming laptop",799));
	std::shared_ptr<Item> item3(new AntiqueItem("AI2","doremon","my personal favourite",15));


    // 2. Verify that the attributes (itemId, startingPrice) are correctly set.
	assertTrue(item1->getItemId()=="AI1","item id is wrong");
	assertTrue(item1->getStartingPrice()==150,"starting price wrong");

    // Test pure virtual method
    // 1. Verify that the overridden method (getItemType) returns the expected result for an AntiqueItem.
	assertTrue(item1->getItemType()=="AntiqueItem","overloading not working");
	cout<<endl;
    // Test displayInfo (requires visual verification)
    // 1. Call displayInfo and visually verify the output for correctness.
	item1->displayInfo();

    // Test JSON conversion
    // 1. Convert the Item object to JSON.
    // 2. Verify that the JSON contains expected fields (e.g., itemId).
	auto poco= item1->toJson();
	assertTrue(poco->getValue<string>("Id")=="AI1","poco object is wrong");




}

// Test cases for Auction class
void testAuction() {
    // Test bid placement
    // 1. Create an Auction object with a specific Item.
    // 2. Create a Buyer object.
    // 3. Place a bid on the Auction by the Buyer.
    // 4. Verify that the highest bid and highest bidder are correctly updated.

	std::shared_ptr<Item> item1(new AntiqueItem("AI1","table","IKEA Table with variable hight",150));
	Auction auction("A1",item1);

	std::shared_ptr<User> bhavin(new Buyer("123","bhavin","prajapti@gmail.com",10000));
	std::shared_ptr<User> rutvik(new Buyer("456","rutvik","pradhan@gmail.com",1000));

	auction.placeBid(bhavin,200);

	auction.placeBid(bhavin,250);
	assertTrue(auction.getHighestBid()==250,"highest bid not updated");

	auction.placeBid(bhavin,500);


	auto highestbidder= auction.getHighestBidder();

	assertTrue(highestbidder->getUserId()==bhavin->getUserId(),"highest bidder not updated");

    // Test ending the auction
    // 1. End the auction and verify that the result (winner) is as expected.
	assertTrue(auction.endAuction()->getUserId()==bhavin->getUserId(),"winner not correct");
	cout<<endl<<bhavin->getBalance()<<endl;

	cout<<"i amhereeeeeeeeeeeee"<<endl;
	cout<<auction.toJson()->getValue<string>("item");
    // Test JSON conversion
    // 1. Convert the Auction object to JSON.
    // 2. Verify that the JSON contains expected fields (e.g., auctionId).
}

// Test cases for Bid class
void testBid() {
    // Test getters
    // 1. Create a Bid object with specific Buyer and amount.
    // 2. Verify that the getters return the correct Buyer and amount.

    // Test JSON conversion
    // 1. Convert the Bid object to JSON.
    // 2. Verify that the JSON contains expected fields (e.g., amount).
}

// Test cases for AuctionManager class
void testAuctionManager() {
    // Test starting auctions
    // 1. Create multiple Item objects.
    // 2. Start auctions for these items using AuctionManager.
    // 3. Verify that the auctions are correctly started.

	cout<<endl;
	cout<<"Auction Mangaer"<<endl;	cout<<endl;

	std::shared_ptr<Item> laptop(new ElectronicItem("EI1","laptop","HP gaming laptop",799));
	std::shared_ptr<Item> doremon(new AntiqueItem("AI2","doremon","my personal favourite",15));

	laptop->displayInfo();
	cout<<endl;

	doremon->displayInfo();
	cout<<endl;

	AuctionManager manager;
	manager.startAuction("1",laptop);
	manager.startAuction("2",doremon);

	auto onAuctions=manager.getActiveAuctions();
	assertTrue(onAuctions.size()==2,"active auctions are wrong");

	std::shared_ptr<User> bhavin(new Buyer("123","bhavin","prajapti@gmail.com",10000));
	std::shared_ptr<User> rutvik(new Buyer("456","rutvik","pradhan@gmail.com",1000));
	cout<<endl;

	bhavin->displayInfo();
	cout<<endl;

	rutvik->displayInfo();
	cout<<endl;

    // Test placing bids
    // 1. Place bids on multiple auctions through AuctionManager.
    // 2. Verify that the bids are correctly processed.
	manager.placeBid("1",rutvik,850);
	manager.placeBid("1",bhavin,900);
	manager.placeBid("2",bhavin,100);
	manager.placeBid("1",rutvik,950);
	manager.placeBid("1",bhavin,970);
	manager.placeBid("1",rutvik,990);





    // Test ending auctions
    // 1. End multiple auctions through AuctionManager.
	auto laptopWinner=manager.endAuction("1");
	auto doremonWinner=manager.endAuction("2");

    // 2. Verify that the correct winners are determined.
	assertTrue(laptopWinner->getUserId()== rutvik->getUserId(),"winner is incorrect");
	assertTrue(doremonWinner->getUserId()== bhavin->getUserId(),"winner is incorrect");

    // Test getting active auctions
    // 1. Retrieve active auctions from AuctionManager.
    // 2. Verify that no active auctions exist after all are ended.
	auto actives=manager.getActiveAuctions();
	assertTrue(actives.size()==0,"there should be no active auctions");
	cout<<endl;

	cout<<"laptop buyer: "<<laptopWinner->getName();
	cout<<endl;
	cout<<"doremon buyer: "<<doremonWinner->getName();
	cout<<endl;
	cout<<endl;
	cout<<"Rutvik's remaning balance: "<<rutvik->getBalance()<<endl;
	cout<<"Bhavin's remaning balance: "<<bhavin->getBalance()<<endl;

    // Test JSON conversion
    // 1. Convert AuctionManager state to JSON.
    // 2. Verify that the JSON contains expected fields (e.g., auctions list).
}

// Performance test cases
void testPerformance() {
    // Simulate high load
    // 1. Create an Item and start an auction for it.
    // 2. Simulate placing a large number of bids in a multithreaded environment.
    // 3. Measure and report the time taken for processing.

    // Test performance metrics
    // 1. Ensure that performance meets acceptable thresholds (e.g., execution time).
}

// Exception handling test cases
void testExceptionHandling() {
    // Test invalid operations
    // 1. Attempt to place a bid with an invalid auction ID.

    // 2. Attempt to end an auction with an invalid auction ID.

    // 3. Verify that appropriate exceptions are thrown and handled.

}

void allTests(){
    // Run all test functions
    testUser();
    testItem();
    testAuction();
    testBid();
    testAuctionManager();
    testPerformance();
    testExceptionHandling();
}
