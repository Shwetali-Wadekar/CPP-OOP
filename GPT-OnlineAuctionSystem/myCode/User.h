/*
 * User.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef USER_H_
#define USER_H_

#include <string>
#include <memory>
#include <Poco/JSON/Object.h>

/**
 * Base class for users in the auction system. (10 points)
 */
class User {
protected:
    std::string userId;
    std::string name;
    std::string email;
    double balance;

public:
    /**
     * Initializes a new user with the given details. (3 points)
     *
     * @param userId The unique identifier for the user
     * @param name The name of the user
     * @param email The email of the user
     * @param balance The balance in the user's account
     */
    User(const std::string& userId, const std::string& name, const std::string& email, double balance);

    /**
     * Pure virtual method to return user role. (2 points)
     *
     * @return The user role
     */
    virtual std::string getUserRole() const = 0;

    /**
     * Returns the user ID. (1 point)
     *
     * @return The user ID
     */
    std::string getUserId() const;

    /**
     * Returns the user's balance. (1 point)
     *
     * @return The balance
     */
    double getBalance() const;

    /**
     * Updates the user's balance. (2 points)
     *
     * @param amount The amount to update
     */
    void updateBalance(double amount);

    /**
     * Displays user information. (3 points)
     */
    virtual void displayInfo() const;

    /**
     * Converts the user details to a JSON object. (3 points)
     *
     * @return A JSON object with user details
     */
    virtual std::shared_ptr<Poco::JSON::Object> toJson() const;
	const std::string& getName() const;
};

#endif /* USER_H_ */
