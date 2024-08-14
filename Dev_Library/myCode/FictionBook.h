#ifndef FICTIONBOOK_H_
#define FICTIONBOOK_H_

#include "Book.h"

/**
 * Represents a fiction book in the library.
 */
class FictionBook : public Book {
public:
    /**
     * Creates a new fiction book with the given id, title, and author.
     *
     * @param id the book id
     * @param title the book title
     * @param author the book author
     */
    FictionBook(const std::string& id, const std::string& title, const std::string& author);
};

#endif /* FICTIONBOOK_H_ */
