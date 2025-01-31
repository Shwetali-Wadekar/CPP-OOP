/*
 * BookCatalog.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef BOOKCATALOG_H_
#define BOOKCATALOG_H_


#include "Book.h"
#include "DuplicateBookException.h"

/**
 * Manages a collection of books in the bookstore. (20 points)
 */
class BookCatalog {
private:
    std::map<std::string, std::unique_ptr<Book>> books;

public:
    /**
     * Adds a book to the catalog. If a book with the same ISBN already exists,
     * throws a DuplicateBookException. (5 points)
     *
     * @param book the book to add
     * @throws DuplicateBookException
     */
    void addBook(unique_ptr<Book> book);

    /**
     * Removes a book from the catalog by its ISBN. If no such book exists, does nothing. (3 points)
     *
     * @param isbn the ISBN of the book to remove
     */
    void removeBook(const string& isbn);

    /**
     * Searches for a book by its ISBN and returns a pointer to it.
     * If no such book exists, returns nullptr. (3 points)
     *
     * @param isbn the ISBN to search for
     * @return a pointer to the book, or nullptr if not found
     */
    Book* searchByIsbn(const string& isbn) const;

    /**
     * Searches for books by an author and returns a vector of pointers to them. (3 points)
     *
     * @param author the author to search for
     * @return a vector of pointers to books by the author
     */
    vector<Book*> searchByAuthor(const string& author) const;

    /**
     * Returns all books sorted by title. (3 points)
     *
     * @return a vector of pointers to all books sorted by title
     */
    vector<Book*> getAllBooksSortedByTitle() const;
};

#endif /* BOOKCATALOG_H_ */
