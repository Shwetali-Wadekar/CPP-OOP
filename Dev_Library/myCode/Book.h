#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <memory>
#include <list>

class Member;

/**
 * Represents a book in the library.
 */
class Book {
private:
    std::string id;
    std::string title;
    std::string author;
    std::weak_ptr<Member> borrowedBy; // Aggregation

public:
    /**
     * Creates a new book with the given id, title, and author.
     *
     * @param id the book id
     * @param title the book title
     * @param author the book author
     */
    Book(const std::string& id, const std::string& title, const std::string& author);

    /**
     * Returns the book's id.
     *
     * @return the id
     */
    std::string getId() const;

    /**
     * Returns the book's title.
     *
     * @return the title
     */
    std::string getTitle() const;

    /**
     * Returns the book's author.
     *
     * @return the author
     */
    std::string getAuthor() const;

    /**
     * Borrows the book to a member.
     *
     * @param member the member borrowing the book
     */
    void borrowBook(std::shared_ptr<Member> member);

    /**
     * Returns the book to the library.
     */
    void returnBook();

    /**
     * Returns the member who borrowed the book.
     *
     * @return the member or nullptr if the book is not borrowed
     */
    std::shared_ptr<Member> getBorrower() const;
};

#endif /* BOOK_H_ */
