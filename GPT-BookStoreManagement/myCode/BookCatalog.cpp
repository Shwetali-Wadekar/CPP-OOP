/*
 * BookCatalog.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "BookCatalog.h"
#include<set>
//    std::map<std::string, std::unique_ptr<Book>> books;

void BookCatalog::addBook(unique_ptr<Book> book)
{
	auto found = books.find(book->getIsbn());

	if( found == books.end()) {
		books.insert(std::make_pair(book->getIsbn(),std::move(book)));
	}else {
		throw DuplicateBookException(book->getIsbn());
	}
}

void BookCatalog::removeBook(const string &isbn)
{
	auto found = books.find(isbn);
	if( found != books.end()) {
		books.erase(isbn);
	}


}

Book* BookCatalog::searchByIsbn(const string &isbn) const
{
	auto found = books.find(isbn);
	if( found != books.end()) {
		return found->second.get();
	}
		return nullptr;

}

vector<Book*> BookCatalog::searchByAuthor(const string &author) const{
	vector<Book*> authorBooks;
	for(auto iter=books.begin() ; iter != books.end() ; ++iter) {
		if((*iter).second->getAuthor()==author) {
			authorBooks.push_back((*iter).second.get());
		}
	}
	return authorBooks;
}

vector<Book*> BookCatalog::getAllBooksSortedByTitle() const
{
	vector<Book*> sameTitleBooks;
	std::set<std::string> titles;

	for(auto iter=books.begin() ; iter != books.end() ; ++iter) {

		titles.insert((*iter).second->getTitle());

	}
	for(auto iter=titles.begin() ; iter != titles.end() ; ++iter) {
		for(auto i=books.begin(); i != books.end() ; ++i) {
			if( (*i).second.get()->getTitle()==(*iter)) {
				sameTitleBooks.push_back((*i).second.get());

			}
		}
	}
	return sameTitleBooks;
}

