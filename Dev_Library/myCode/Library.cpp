/*
 * Library.cpp
 *
 *  Created on: 28 Jul 2024
 *      Author: devma
 */

#include "Library.h"
#include "Book.h"
#include "Member.h"

   // std::map<std::string, std::unique_ptr<Book>> books;

Book* Library::addBook(const std::string &title, const std::string &author)
{
	std::unique_ptr<Book> book(new Book("B"+std::to_string(this->nextBookNumber),title,author));
	Book* bookPtr=book.get();
	books.insert(std::make_pair(bookPtr->getId(),std::move(book)));
	nextBookNumber++;

	return bookPtr;
}

Book* Library::lookupBook(const std::string &id) const
{
	auto found= books.find(id);

	if(found != books.end()) {
		return found->second.get();
	}else {
		return nullptr;
	}
	return nullptr;
}

std::vector<Book*> Library::allBooks() const
{

	std::vector<Book*> allbooks;
	for(auto iter = books.begin() ; iter != books.end() ; ++iter) {
		allbooks.push_back((*iter).second.get());
	}
	return allbooks;
}

Member* Library::addMember(const std::string &name)
{
	std::unique_ptr<Member> member(new Member("M"+std::to_string(this->nextMemberNumber),name));
	Member* memberPtr=member.get();
	members.insert(std::make_pair(memberPtr->getId(),std::move(member)));
	nextMemberNumber++;

	return memberPtr;
}

Member* Library::lookupMember(const std::string &id) const
{
	auto found= members.find(id);

	if(found != members.end()) {
		return found->second.get();
	}else {
		return nullptr;
	}
	return nullptr;
}


std::vector<Member*> Library::allMembers() const
{

	std::vector<Member*> allbooks;
	for(auto iter = members.begin() ; iter != members.end() ; ++iter) {
		allbooks.push_back((*iter).second.get());
	}
	return allbooks;
}
