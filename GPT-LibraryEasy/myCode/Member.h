#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>
#include <vector>
#include <Poco/JSON/Object.h>
#include "Library.h"

class Book;

class Member {
private:
    std::string id;
    std::string firstName;
    std::string lastName;
    std::vector<Book*> borrowedBooks;

public:
    Member(std::string id, std::string firstName, std::string lastName);
    std::string getId() const;
    void borrowBook(Book* book);
    void returnBook(Book* book);
    std::vector<Book*> getBorrowedBooks() const;
    Poco::JSON::Object::Ptr toJson() const;
	const std::string& getFirstName() const;
	void setId(const std::string &id);
	const std::string& getLastName() const;
};

std::ostream& operator<<(std::ostream& lhs, Member& rhs);
#endif /* MEMBER_H_ */
