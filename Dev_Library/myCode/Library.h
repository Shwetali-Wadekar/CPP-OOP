/*
 * Library.h
 *
 *  Created on: 28 Jul 2024
 *      Author: devma
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <memory>
#include <map>
#include <vector>

class Book;
class Member;

/**
 * Represents the Library. In the scope of this exercise, the properties
 * of the library are reduced to "a library has books and members".
 */
class Library {
private:
    /** The number of the next book that is created by an
     * invocation of #addBook() */
    unsigned int nextBookNumber = 1;

    /** The book directory. Books are stored by their id. */
    std::map<std::string, std::unique_ptr<Book>> books;

    /** The member directory. Members are stored by their id. */
    std::map<std::string, std::unique_ptr<Member>> members;
    unsigned int nextMemberNumber = 1;


public:
    /**
     * Creates a new book, assigning it the next available id
     * (see #nextBookNumber). The book is added to the book
     * directory (see #books).
     */
    Book* addBook(const std::string& title, const std::string& author);

    /**
     * Looks up a book in the book directory by its id.
     *
     * @param id the book id
     * @return a pointer to the book or nullptr if no book
     * with this id exists
     */
    Book* lookupBook(const std::string& id) const;

    /**
     * Returns pointers to all books of the library.
     *
     * @return the books
     */
    std::vector<Book*> allBooks() const;

    /**
     * Creates a new member, assigning it the next available id.
     * The member is added to the member directory (see #members).
     */
    Member* addMember(const std::string& name);

    /**
     * Looks up a member in the member directory by its id.
     *
     * @param id the member id
     * @return a pointer to the member or nullptr if no member
     * with this id exists
     */
    Member* lookupMember(const std::string& id) const;

    /**
     * Returns pointers to all members of the library.
     *
     * @return the members
     */
    std::vector<Member*> allMembers() const;
};

#endif /* LIBRARY_H_ */
