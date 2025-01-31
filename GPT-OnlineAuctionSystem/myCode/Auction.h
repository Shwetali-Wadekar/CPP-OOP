/*
 * Auction.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef AUCTION_H_
#define AUCTION_H_


#include "Item.h"
#include "User.h"
#include <vector>
#include <mutex>
#include <thread>
#include <Poco/JSON/Object.h>

/**
 * Represents an auction for an item. (20 points)
 */
class Auction {
private:
    std::string auctionId;
    std::shared_ptr<Item> item;
    std::vector<std::shared_ptr<User>> bidders;
   // std::mutex mtx;
    double highestBid;
    std::shared_ptr<User> highestBidder;

public:
    /**
     * Initializes a new auction with the given item. (5 points)
     *
     * @param auctionId The unique identifier for the auction
     * @param item The item to be auctioned
     */
    Auction(const std::string& auctionId, const std::shared_ptr<Item>& item);

    /**
     * Places a bid on the auction. (5 points)
     *
     * @param user The user placing the bid
     * @param bidAmount The amount of the bid
     */
    void placeBid(const std::shared_ptr<User>& user, double bidAmount);

    /**
     * Returns the highest bid amount. (2 points)
     *
     * @return The highest bid
     */
    double getHighestBid() const;

    /**
     * Returns the highest bidder. (2 points)
     *
     * @return The highest bidder
     */
    std::shared_ptr<User> getHighestBidder() const;

    /**
     * Ends the auction and returns the winner. (6 points)
     *
     * @return The winner of the auction
     */
    std::shared_ptr<User> endAuction();

    /**
      *
     * @return A JSON object with auction details
     */
    std::shared_ptr<Poco::JSON::Object> toJson() const;
	const std::string& getAuctionId() const;
};

#endif /* AUCTION_H_ */
