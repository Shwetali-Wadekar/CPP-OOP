/*
 * Book.cpp
 *
 *  Created on: 29 Jul 2024
 *      Author: hp
 */

#include "Book.h"

Book::Book(std::string id, std::string title, std::string author) : id(id), title(title) , author(author)
{
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

bool Book::getIsBorrowed() const
{
	return this->isBorrowed;
}

void Book::setBorrowed(bool borrowed)
{
	this->isBorrowed= borrowed;
}
//
//Poco::JSON::Object::Ptr Book::toJson() const
//{
//}
