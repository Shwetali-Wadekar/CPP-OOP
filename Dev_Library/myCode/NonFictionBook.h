#ifndef NONFICTIONBOOK_H_
#define NONFICTIONBOOK_H_

#include "Book.h"

/**
 * Represents a non-fiction book in the library.
 */
class NonFictionBook : public Book {
public:
    /**
     * Creates a new non-fiction book with the given id, title, and author.
     *
     * @param id the book id
     * @param title the book title
     * @param author the book author
     */
    NonFictionBook(const std::string& id, const std::string& title, const std::string& author);
};

#endif /* NONFICTIONBOOK_H_ */
