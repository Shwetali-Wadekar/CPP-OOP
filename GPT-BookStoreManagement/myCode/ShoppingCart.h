/*
 * ShoppingCart.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef SHOPPINGCART_H_
#define SHOPPINGCART_H_


#include "Book.h"

/**
 * Models a shopping cart for a customer. (20 points)
 */
class ShoppingCart {
private:
    vector<Book*> cart;
    double totalCost;

public:
    /**
     * Initializes an empty shopping cart. (2 points)
     */
    ShoppingCart();

    /**
     * Adds a book to the cart and updates the total cost. (3 points)
     *
     * @param book the book to add
     */
    void addBook(Book* book);

    /**
     * Removes a book from the cart by its ISBN and updates the total cost.
     * If no such book exists in the cart, does nothing. (3 points)
     *
     * @param isbn the ISBN of the book to remove
     */
    void removeBook(const string& isbn);

    /**
     * Returns the total cost of all books in the cart. (2 points)
     *
     * @return the total cost
     */
    double getTotalCost() const;

    /**
     * Returns a list of all books in the cart. (2 points)
     *
     * @return a vector of pointers to books in the cart
     */
    vector<Book*> getBooks() const;

    /**
     * Clears all books from the cart and resets the total cost to 0. (2 points)
     */
    void clearCart();
};
#endif /* SHOPPINGCART_H_ */
