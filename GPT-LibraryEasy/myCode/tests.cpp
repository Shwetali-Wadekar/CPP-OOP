/*
 * tests.cpp
 *
 *  Created on: 29 Jul 2024
 *      Author: hp
 */

#include "Library.h"
#include "Member.h"
#include "Book.h"
#include "FictionBook.h"
#include "NonFictionBook.h"
#include <iostream>
#include <sstream>
#include <set>
#include <Poco/JSON/Stringifier.h>
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
 * Initializes a library with members and books.
 * Can be used as data for various tests.
 */
void setupLibrary(Library& library) {
    Member* m1 = library.createMember("Alice", "Angel");
    Member* m2 = library.createMember("Bob", "Billings");
    Member* m3 = library.createMember("Caesar", "Chase");
//
    library.addBook(make_unique<FictionBook>("0000000001", "Book A", "Author X"));
    library.addBook(make_unique<NonFictionBook>("0000000002", "Book B", "Author Y"));
    library.addBook(make_unique<FictionBook>("0000000003", "Book C", "Author Z"));
//
    m1->borrowBook(library.lookupBook("0000000001"));
    m2->borrowBook(library.lookupBook("0000000002"));
    m3->borrowBook(library.lookupBook("0000000003"));
}

void libraryTests() {
    Library library;
    setupLibrary(library);

    // Assert that the library has three members.
    assertTrue(library.allMembers().size()==3,"Library did not have 3 members");

    // Assert that the member with id "1" can be looked up.
    assertTrue(library.lookupMember("1") != nullptr, "id 1 member can not be looked up");

    // Assert that there is no member with id "42".
    assertTrue(library.lookupMember("42") == nullptr, "id 42 member exist");

    // Assert that the library has three books.
    assertTrue(library.allBooks().size()==3,"Library did not have 3 books");

    // Assert that the book with id "0000000002" can be looked up.
    assertTrue(library.lookupBook("0000000002") != nullptr, "id 0000000002 book can not be looked up");

    // Assert that there is no book with id "42".
    assertTrue(library.lookupBook("42") == nullptr, "id 42 member exist");

}

void memberTests() {
    // Create a LibraryMember with sample data.
	Library mylib;
    setupLibrary(mylib);

    // Assert that invoking the overloaded left shift operator produces the expected result.
    Member bhavin("1","Bhavin","Prajapati");
    std::ostringstream oss;
    oss<<bhavin;
    string expected ="1: Bhavin, Prajapati";

    assertTrue(oss.str()==expected,"operator overloading is not working");
    // Add a book loan to the member.

    // Remove a book loan from the member.
}

void bookTests() {
    Library library;
    setupLibrary(library);

    // Lookup Book "0000000001" (Book A), assert that it is found.


    // Assert that Book A is borrowed.
    assertTrue(library.lookupBook("0000000001")->getIsBorrowed() == true, "book a is not borrowed");

    // Assert that returning Book A sets its status to not borrowed.

    vector<Member*> allMembers=library.allMembers();
    assertTrue(library.lookupBook("0000000001")->getIsBorrowed() == false, "book a borrowed");

    for(auto iter = allMembers.begin() ; iter != allMembers.end() ; ++iter) {
    	vector<Book*> allbooks=(**iter).getBorrowedBooks();
    	bool memberFound=false;
    	Book* foundBook=nullptr;
    	for(auto it= allbooks.begin() ; it != allbooks.end() ; ++it) {
    		if((**it).getTitle()== "Book A") {
    			foundBook= (*it);
    			memberFound=true;
    		}
    	}
    	if(memberFound) {
    		(**iter).returnBook(foundBook);
    	}
    }


    assertTrue(library.lookupBook("0000000001")->getIsBorrowed() == false, "book a is not borrowed");
   // library.lookupMember("50")->

    // Assert that borrowing Book A again sets its status to borrowed.
    library.lookupMember("1")->borrowBook(library.lookupBook("0000000001"));
    assertTrue(library.lookupBook("0000000001")->getIsBorrowed() == true, "book a is not borrowed again");

}


void allTests() {
    libraryTests();
    memberTests();
    bookTests();
}


