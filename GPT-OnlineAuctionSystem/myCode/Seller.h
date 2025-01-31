/*
 * Seller.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef SELLER_H_
#define SELLER_H_

#include "User.h"

/**
 * Represents a seller in the auction system. (5 points)
 */
class Seller : public User {
	std::string role="Seller";
public:
    /**
     * Initializes a new seller with the given details. (2 points)
     *
     * @param userId The unique identifier for the user
     * @param name The name of the user
     * @param email The email of the user
     * @param balance The balance in the user's account
     */
    Seller(const std::string& userId, const std::string& name, const std::string& email, double balance);

    /**
     * Returns the user role. (1 point)
     *
     * @return The user role
     */
    std::string getUserRole() const override;

    /**
     * Displays seller information. (2 points)
     */
    void displayInfo() const override;
};


#endif /* SELLER_H_ */
