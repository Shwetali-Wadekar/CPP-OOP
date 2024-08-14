/*
 * DuplicateBookException.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef DUPLICATEBOOKEXCEPTION_H_
#define DUPLICATEBOOKEXCEPTION_H_

#include <stdexcept>
#include<string>

/**
 * An exception thrown when a book with the same ISBN is added to the catalog. (2 points)
 */
class DuplicateBookException: public std::invalid_argument {
public:
    /**
     * Initializes a new instance with the given ISBN. (2 points)
     *
     * @param isbn the ISBN of the duplicate book
     */
    DuplicateBookException(const std::string& isbn);
};

#endif /* DUPLICATEBOOKEXCEPTION_H_ */
