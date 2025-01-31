/*
 * test.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */


#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <stdexcept>
#include<map>
#include<set>
#include "BookCatalog.h"
#include "ShoppingCart.h"
#include "OrderManager.h"
#include<cstdint>
#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::seconds
/**
 * Performs all tests on the bookstore system. (30 points)
 */


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

void allTests() {
	// Test Book class
	// TODO: Implement tests for Book class (5 points)
	Book b1("abc of life","bhavin","9574516057",999);

	assertTrue(b1.getAuthor()=="bhavin","author is not correct");
	assertTrue(b1.getIsbn()=="9574516057","isbn is not correct");
	assertTrue(b1.getPrice()==999,"price is not correct");
	assertTrue(b1.getTitle()=="abc of life","title wrong");

	// Test BookCatalog class
	// TODO: Implement tests for BookCatalog class (5 points)

	Book* book1ptr=new Book("abc of life","bhavin","9574516057",999);
	Book* book2ptr=new Book("surat love of my life","bhavin","5410239875",499);
	Book* book3ptr=new Book("schwabish gemund the hell of Germany","rutvik","1235896475",49);
	Book* book4ptr=new Book("mannheim the mini istambul","bhavin","9845125554",1499);
	Book* book5ptr=new Book("learning how to write","dev","6596662211",19);
	Book* book6ptr=new Book("xyz of philosophy","rutvik","4578541209",99);

	unique_ptr<Book> book1(book1ptr);
	unique_ptr<Book> book2(book2ptr);
	unique_ptr<Book> book3(book3ptr);
	unique_ptr<Book> book4(book4ptr);
	unique_ptr<Book> book5(book5ptr);
	unique_ptr<Book> book6(book6ptr);

	BookCatalog catalog;
	catalog.addBook(move(book1));
	catalog.addBook(move(book2));
	catalog.addBook(move(book3));
	catalog.addBook(move(book4));
	catalog.addBook(move(book5));
	catalog.addBook(move(book6));

	std::string expectedSortedTitles[]={"abc of life","learning how to write","mannheim the mini istambul",
			"schwabish gemund the hell of Germany","surat love of my life","xyz of philosophy"};

	vector<Book*> sortedBooks=catalog.getAllBooksSortedByTitle();

//	for(auto i:sortedBooks) {
//		cout<<i->getTitle()<<endl;
//	}

	for(size_t i=0;i<sortedBooks.size() ; i++) {
		assertTrue(expectedSortedTitles[i]==sortedBooks.at(i)->getTitle(),"not sorted by title");
	}

	vector<Book*> authorBooks=catalog.searchByAuthor("dev");
	for(size_t i=0;i<authorBooks.size() ; i++) {
		assertTrue(authorBooks[i]->getIsbn()=="6596662211","sorted by order working");
	}

	catalog.removeBook(book1ptr->getIsbn());
	assertTrue(catalog.searchByIsbn(book1ptr->getIsbn())==nullptr,"book is not removed");


	// Test ShoppingCart class
	// TODO: Implement tests for ShoppingCart class (5 points)

	ShoppingCart cart;
	cart.addBook(book2ptr);
	cart.addBook(book3ptr);

	vector<Book*> bookInMyCart=cart.getBooks();
	assertTrue(bookInMyCart.size()==2,"getbook is not working");

	assertTrue(cart.getTotalCost()==(book2ptr->getPrice()+book3ptr->getPrice()),"total price in cart is wrong");

	cart.removeBook(book2ptr->getIsbn());
	vector<Book*> bookInMyCart2=cart.getBooks();

//	for(auto i: bookInMyCart2) {
//		cout<<i->getTitle()<<endl;
//	}

	assertTrue(bookInMyCart2.size()==1,"book not removed");
	//cout<<cart.getTotalCost();
	assertTrue(cart.getTotalCost()==book3ptr->getPrice(),"book not removed");

	cart.clearCart();
	vector<Book*> bookInMyCart3=cart.getBooks();
	assertTrue(bookInMyCart3.size()==0,"clear cart not working");


	// Test Order class
	// TODO: Implement tests for Order class (5 points)

	ShoppingCart cartForOrder;
	cartForOrder.addBook(book2ptr);
	cartForOrder.addBook(book3ptr);
	cartForOrder.addBook(book4ptr);

	Order order(cartForOrder,"1");
	vector<Book*> orderedBooks=order.getBooks();


	set<Book*> expectedOrderdBooks = {book2ptr,book3ptr,book4ptr};

	for(size_t i=0 ; i<orderedBooks.size() ;i++) {
		assertTrue(expectedOrderdBooks.find(orderedBooks.at(i))!=expectedOrderdBooks.end(),"all books in in order");
	}


	assertTrue(order.getTotalCost()==cartForOrder.getTotalCost(),"order total wrong");
	//Order* orderptr1= new Order(cartForOrder,"1");


	// Test OrderManager class
	// TODO: Implement tests for OrderManager class (5 points)

	OrderManager manager;

	ShoppingCart cartForOrder2;
	cartForOrder2.addBook(book6ptr);


	Order* orderptr2= new Order(cartForOrder2,"2");
	unique_ptr<Order> o2(orderptr2);
    std::this_thread::sleep_for(std::chrono::seconds(2));

	Order* orderptr3= new Order(cartForOrder,"3");
	unique_ptr<Order> o3(orderptr3);
    std::this_thread::sleep_for(std::chrono::seconds(2));

	Order* orderptr1= new Order(cartForOrder,"1");
	unique_ptr<Order> o1(orderptr1);


	cout<<o3.get()->getOrderDate()<<endl;
	cout<<o2.get()->getOrderDate()<<endl;
	cout<<o1.get()->getOrderDate()<<endl;

	manager.addOrder(move(o2));
	manager.addOrder(move(o1));
	manager.addOrder(move(o3));

	auto allorder=manager.getAllOrdersSortedByDate();

	for(auto i: allorder) {
		cout<<i->getOrderId();
	}

	uint16_t timesta=time(0);

	// Comprehensive integration tests
	// TODO: Implement comprehensive integration tests (5 points)
}

