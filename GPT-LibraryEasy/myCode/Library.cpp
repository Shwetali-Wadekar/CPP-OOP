/*
 * Library.cpp
 *
 *  Created on: 29 Jul 2024
 *      Author: hp
 */

#include "Library.h"
#include "Book.h"
#include "Member.h"

using namespace std;
//    std::map<std::string, std::unique_ptr<Member>> members;

Member* Library::createMember(std::string firstName, std::string lastName)
{
	std::unique_ptr<Member> member = std::unique_ptr<Member>(new Member(to_string(nextMemberID),firstName,lastName));
	Member* memberPtr = member.get();
	members.insert(make_pair(to_string(nextMemberID),move(member)));
	nextMemberID++;
	return memberPtr;
}

Member* Library::lookupMember(std::string id) const
{
	auto found = members.find(id);
	if( found != members.end()) {
		return found->second.get();
	}else {
		return nullptr;
	}
}

std::vector<Member*> Library::allMembers() const
{
	vector<Member*> allMembers;
	for(auto iter = members.begin() ; iter != members.end() ; ++iter) {
		allMembers.push_back((*iter).second.get());
	}
	return allMembers;
}

//    std::vector<std::unique_ptr<Book>> books;

void Library::addBook(std::unique_ptr<Book> book)
{
	books.push_back(move(book));
}

std::vector<Book*> Library::allBooks() const
{
	vector<Book*> allBooks;

	for(auto iter = books.begin() ; iter != books.end() ; ++iter) {
		allBooks.push_back(iter->get());
	}
	return allBooks;

}

Book* Library::lookupBook(std::string id) const
{
	//auto foundIter=books.begin();
	//auto found=false;
	for(auto iter = books.begin() ; iter != books.end() ; ++iter) {
		if((**iter).getId() == id) {
			//found = true;
			//foundIter=iter;
			return (*iter).get();
		}
	}

	return nullptr;
	//if()
}
