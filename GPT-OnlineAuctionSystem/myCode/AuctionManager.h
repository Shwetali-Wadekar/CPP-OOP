/*
 * AuctionManager.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef AUCTIONMANAGER_H_
#define AUCTIONMANAGER_H_


#include "Auction.h"
#include <map>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <Poco/JSON/Object.h>

/**
 * Manages all auctions in the system. (20 points)
 */
class AuctionManager {
private:
    std::map<std::string, std::shared_ptr<Auction>> auctions;
    //std::mutex mtx;
    //std::condition_variable cv;

public:
    /**
     * Starts a new auction with the given item. (5 points)
     *
     * @param auctionId The unique identifier for the auction
     * @param item The item to be auctioned
     */
    void startAuction(const std::string& auctionId, const std::shared_ptr<Item>& item);

    /**
     * Places a bid on an auction. (5 points)
     *
     * @param auctionId The auction ID
     * @param user The user placing the bid
     * @param bidAmount The bid amount
     */
    void placeBid(const std::string& auctionId, const std::shared_ptr<User>& user, double bidAmount);

    /**
     * Ends an auction and announces the winner. (5 points)
     *
     * @param auctionId The auction ID
     * @return The winner of the auction
     */
    std::shared_ptr<User> endAuction(const std::string& auctionId);

    /**
     * Returns a list of all active auctions. (5 points)
     *
     * @return A list of active auctions
     */
    std::vector<std::shared_ptr<Auction>> getActiveAuctions() const;

    /**
     * Converts the auction manager details to a JSON object. (5 points)
     *
     * @return A JSON object with auction manager details
     */
    std::shared_ptr<Poco::JSON::Object> toJson() const;
};

#endif /* AUCTIONMANAGER_H_ */
