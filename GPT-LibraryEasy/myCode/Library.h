#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <memory>
#include <map>
#include <vector>

class Book;
class Member;

class Library {
private:
    unsigned int nextMemberID = 1;
    std::map<std::string, std::unique_ptr<Member>> members;
    std::vector<std::unique_ptr<Book>> books;

public:
    Member* createMember(std::string firstName, std::string lastName);
    Member* lookupMember(std::string id) const;
    std::vector<Member*> allMembers() const;

    void addBook(std::unique_ptr<Book> book);
    std::vector<Book*> allBooks() const;
    Book* lookupBook(std::string id) const;
};

#endif /* LIBRARY_H_ */
