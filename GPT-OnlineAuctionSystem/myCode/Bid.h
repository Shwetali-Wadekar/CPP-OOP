/*
 * Bid.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef BID_H_
#define BID_H_


#include "User.h"
#include "Item.h"
#include <Poco/JSON/Object.h>

/**
 * Represents a bid placed on an auction. (10 points)
 */
class Bid {
private:
    std::shared_ptr<User> user;
    double amount;

public:
    /**
     * Initializes a new bid with the given user and amount. (3 points)
     *
     * @param user The user placing the bid
     * @param amount The bid amount
     */
    Bid(const std::shared_ptr<User>& user, double amount);

    /**
     * Returns the user who placed the bid. (2 points)
     *
     * @return The user
     */
    std::shared_ptr<User> getUser() const;

    /**
     * Returns the bid amount. (1 point)
     *
     * @return The amount
     */
    double getAmount() const;

    /**
     * Converts the bid details to a JSON object. (4 points)
     *
     * @return A JSON object with bid details
     */
    std::shared_ptr<Poco::JSON::Object> toJson() const;
};


#endif /* BID_H_ */
