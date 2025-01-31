/*
 * Member.cpp
 *
 *  Created on: 29 Jul 2024
 *      Author: hp
 */

#include "Member.h"
#include "Book.h"
#include <algorithm>

Member::Member(std::string id, std::string firstName, std::string lastName) : id(id) , firstName(firstName) ,lastName(lastName)
{
}

std::string Member::getId() const
{
	return this->id;
}

void Member::borrowBook(Book *book)
{
	if(book->getIsBorrowed()== false) {
		book->setBorrowed(true);
		borrowedBooks.push_back(book);
	}
}

void Member::returnBook(Book *book)
{
	auto dummyIter= borrowedBooks.begin() ;
	//bool flag=false;
	for(auto iter= borrowedBooks.begin() ; iter != borrowedBooks.end() ; ++iter) {
		if((**iter).getId() == book->getId()) {
			dummyIter= iter;
			(**dummyIter).setBorrowed(false);
			borrowedBooks.erase(dummyIter);

			//flag=true;
			break;
		}
	}
//	if( flag) {
//		borrowedBooks.erase(dummyIter);
//		(**dummyIter).setBorrowed(false);
//
//	}
}

std::vector<Book*> Member::getBorrowedBooks() const
{
	return borrowedBooks;
}

std::ostream& operator <<(std::ostream &lhs, Member &rhs)
{
	lhs<<rhs.getId()+": "+rhs.getFirstName()+", "+rhs.getLastName();
	return lhs;
}

const std::string& Member::getFirstName() const
{
	return firstName;
}

void Member::setId(const std::string &id)
{
	this->id = id;
}

const std::string& Member::getLastName() const
{
	return lastName;
}
