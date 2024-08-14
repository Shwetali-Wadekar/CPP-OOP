/*
 * Book.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Book.h"

Book::Book(const string &title, const string &author, const string &isbn,
		double price) :title(title) , author(author) , isbn(isbn) , price(price)
{
}

string Book::getTitle() const
{
	return this->title;
}

string Book::getAuthor() const
{
	return this->author;
}

string Book::getIsbn() const
{
	return this->isbn;
}

double Book::getPrice() const
{
	return this->price;
}

void Book::setPrice(double newPrice)
{
	this->price=newPrice;
}
