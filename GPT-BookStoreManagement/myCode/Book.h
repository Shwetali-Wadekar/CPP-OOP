/*
 * Book.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <vector>
#include <memory>
#include<map>
/**
 * Models a book with a title, author, ISBN, and price.
 */

using namespace std;

class Book {
private:
    std::string title;
    std::string author;
    string isbn;
    double price;

public:
    /**
     * Initializes a new book with the given details. (2 points)
     *
     * @param title the title of the book
     * @param author the author of the book
     * @param isbn the ISBN number of the book
     * @param price the price of the book
     */
    Book(const string& title, const string& author, const string& isbn, double price);

    /**
     * Returns the title of the book. (1 point)
     *
     * @return the title
     */
    string getTitle() const;

    /**
     * Returns the author of the book. (1 point)
     *
     * @return the author
     */
    string getAuthor() const;

    /**
     * Returns the ISBN of the book. (1 point)
     *
     * @return the ISBN
     */
    string getIsbn() const;

    /**
     * Returns the price of the book. (1 point)
     *
     * @return the price
     */
    double getPrice() const;

    /**
     * Sets a new price for the book. (1 point)
     *
     * @param newPrice the new price
     */
    void setPrice(double newPrice);
};

#endif /* BOOK_H_ */
