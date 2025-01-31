/*
 * Book.cpp
 *
 *  Created on: 28 Jul 2024
 *      Author: devma
 */

#include "Book.h"
#include "Member.h"
Book::Book(const std::string &id, const std::string &title,
		const std::string &author) : id(id) , title(title) , author(author)
{
	this->borrowedBy.reset();
}

std::string Book::getId() const
{
	return this->id;
}

std::string Book::getTitle() const
{
	return this->title;
}

std::string Book::getAuthor() const
{
	return this->author;
}

void Book::borrowBook(std::shared_ptr<Member> member)
{
	//borrowedBy.lock()=member;
	std::weak_ptr<Member> weekbook(member);
	this->borrowedBy= weekbook;
}

void Book::returnBook()
{
	this->borrowedBy.reset();
}

std::shared_ptr<Member> Book::getBorrower() const
{
	return this->borrowedBy.lock();

}
