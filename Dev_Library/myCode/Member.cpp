/*
 * Member.cpp
 *
 *  Created on: 28 Jul 2024
 *      Author: devma
 */

#include "Member.h"
//#include "Book.h"
Member::Member(const std::string &id, const std::string &name) : id(id) , name(name)
{
}

std::string Member::getId() const
{
	return this->id;
}

std::string Member::getName() const
{
	return this->name;
}

//    std::vector<std::weak_ptr<Book>> borrowedBooks; // Composition

void Member::borrowBook(std::shared_ptr<Book> book)
{
	if(book->getBorrower() == nullptr) {
		//book->borrowBook(std::shared_ptr<Member>(new Member(*this)));

		book->borrowBook(std::shared_ptr<Member>( this));

		borrowedBooks.push_back(book);

	}
}

void Member::returnBook(std::shared_ptr<Book> book)
{
	for(auto iter = borrowedBooks.begin() ;  iter != borrowedBooks.end() ; ++iter) {
		//(*iter).lock().get()->
		book.get()->returnBook();
		if((*iter).lock()->getId() == book->getId()){
			auto iter2=iter;
			borrowedBooks.erase(iter2);
		}

	}
}

std::vector<std::shared_ptr<Book> > Member::getBorrowedBooks() const
{
	std::vector<std::shared_ptr<Book>> allbooks;

	for(auto iter = borrowedBooks.begin() ;  iter != borrowedBooks.end() ; ++iter) {

		allbooks.push_back(iter->lock());

	}

	return allbooks;
}
