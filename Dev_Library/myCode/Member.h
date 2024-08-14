/*
 * Member.h
 *
 *  Created on: 28 Jul 2024
 *      Author: devma
 */

#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>
#include <vector>
#include <memory>
#include "Book.h"

/**
 * Represents a member of the library.
 */
class Member {
private:
    std::string id;
    std::string name;
    std::vector<std::weak_ptr<Book>> borrowedBooks; // Composition

public:
    /**
     * Creates a new member with the given id and name.
     *
     * @param id the member id
     * @param name the member name
     */
    Member(const std::string& id, const std::string& name);

    /**
     * Returns the member's id.
     *
     * @return the id
     */
    std::string getId() const;

    /**
     * Returns the member's name.
     *
     * @return the name
     */
    std::string getName() const;

    /**
     * Borrows a book for the member.
     *
     * @param book the book to borrow
     */
    void borrowBook(std::shared_ptr<Book> book);

    /**
     * Returns a book for the member.
     *
     * @param book the book to return
     */
    void returnBook(std::shared_ptr<Book> book);

    /**
     * Returns the books borrowed by the member.
     *
     * @return the borrowed books
     */
    std::vector<std::shared_ptr<Book>> getBorrowedBooks() const;
};

#endif /* MEMBER_H_ */
