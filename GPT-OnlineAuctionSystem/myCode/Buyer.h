/*
 * Buyer.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef BUYER_H_
#define BUYER_H_

#include "User.h"

/**
 * Represents a buyer in the auction system. (5 points)
 */
class Buyer : public User {
	std::string role="Buyer";

public:
    /**
     * Initializes a new buyer with the given details. (2 points)
     *
     * @param userId The unique identifier for the user
     * @param name The name of the user
     * @param email The email of the user
     * @param balance The balance in the user's account
     */
    Buyer(const std::string& userId, const std::string& name, const std::string& email, double balance);

    /**
     * Returns the user role. (1 point)
     *
     * @return The user role
     */
    std::string getUserRole() const override;

    /**
     * Displays buyer information. (2 points)
     */
    void displayInfo() const override;
};


#endif /* BUYER_H_ */
