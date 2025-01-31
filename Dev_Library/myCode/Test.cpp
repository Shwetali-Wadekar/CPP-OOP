#include <iostream>
#include <sstream>
#include <set>
#include <memory>
#include "Library.h"
#include "Member.h"
#include "Book.h"
#include "FictionBook.h"
#include "NonFictionBook.h"
#include "BorrowException.h"
#include "ReturnException.h"

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
 * Initializes a library with members and books of different types.
 * Can be used as data for various tests.
 */
void setupLibrary(Library& library) {
    // The following code has been commented out to keep
    // the start project buildable. Remove the comments
    // when you have implemented the required methods.

    /********* reactivate later *********
    auto m1 = library.addMember("Alice");
    auto m2 = library.addMember("Bob");
    auto m3 = library.addMember("Charlie");

    auto b1 = library.addBook("Fiction Book 1", "Author A");
    auto b2 = library.addBook("Non-Fiction Book 1", "Author B");
    auto b3 = library.addBook("Fiction Book 2", "Author C");
    auto b4 = library.addBook("Non-Fiction Book 2", "Author D");

    m1->borrowBook(b1);
    m1->borrowBook(b2);
    m2->borrowBook(b3);
    m3->borrowBook(b4);
    ************************************/
    auto m1 = library.addMember("Alice");
    auto m2 = library.addMember("Bob");
    auto m3 = library.addMember("Charlie");

    Book* b1 =  library.addBook("Fiction Book 1", "Author A");
    auto b2 = library.addBook("Non-Fiction Book 1", "Author B");
    auto b3 = library.addBook("Fiction Book 2", "Author C");
    auto b4 = library.addBook("Non-Fiction Book 2", "Author D");

    std::shared_ptr<Book> book1(new Book(*b1));
    std::shared_ptr<Book> book2(new Book(*b2));
    std::shared_ptr<Book> book3(new Book(*b3));
    std::shared_ptr<Book> book4(new Book(*b4));


    library.lookupMember("M1")->borrowBook(book1);
    library.lookupMember("M1")->borrowBook(book2);
    library.lookupMember("M2")->borrowBook(book3);
    library.lookupMember("M3")->borrowBook(book4);

    //m1->borrowBook(book1);
   // m1->borrowBook(book2);
   // m2->borrowBook(book3);
   // m3->borrowBook(book4);
}

void libraryTests() {
    /**
     * Create a library and initialize it with setupLibrary.
     */
    Library library;
    setupLibrary(library);

    /*
     * (1) Assert that the library has three members.
     */
    assertTrue(library.allMembers().size()==3,"library has not have 3 members");
    std::vector<Member*> allmembers= library.allMembers();



    /*
     * (2) Assert that the member with id "M2" can be looked up.
     */
    assertTrue(library.lookupMember("M2")!= nullptr,"member M2 can not looked up");
    //cout<<library.allBooks().size();

    /*
     * (3) Assert that there is no member with id "M42".
     */
    assertTrue(library.lookupMember("M42")== nullptr,"wrong member id M42 found");

}

void memberTests() {
    /*
     * (1) Create a Member with sample data. Assert that
     * invoking the overloaded left shift operator produces the
     * expected result. (Hint: use a stringstream.)
     */
}

void bookTests() {
    /**
     * Create a library and initialize it with setupLibrary.
     */

	Library lib;
	setupLibrary(lib);

    /*
     * (1) Lookup Book B1 (Fiction Book 1), assert that it is found.
     */
	assertTrue(lib.lookupBook("B1")!=nullptr,"B1 can not looked up");
    /*
     * (2) Assert that Fiction Book 1 is borrowed by Alice (M1).
     */
	//cout<<lib.lookupBook("B1")->getBorrower()->getName();
	assertTrue(lib.lookupBook("B1")->getBorrower()!=nullptr,"B1 can not looked up");

    /*
     * (3) Assert that Non-Fiction Book 2 is borrowed by Charlie (M3).
     */

    /*
     * (4) Assert that an attempt to borrow a book that is already borrowed throws a BorrowException.
     */

    /*
     * (5) Assert that an attempt to return a book that was not borrowed by the member throws a ReturnException.
     */

}

void allTests() {
    libraryTests();
    memberTests();
    bookTests();
}

