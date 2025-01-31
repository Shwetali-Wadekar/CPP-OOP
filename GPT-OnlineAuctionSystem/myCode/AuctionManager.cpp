/*
 * AuctionManager.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "AuctionManager.h"

void AuctionManager::startAuction(const std::string &auctionId,
		const std::shared_ptr<Item> &item)
{
	std::shared_ptr<Auction> auction(new Auction(auctionId,item));
	auctions.insert(std::make_pair(auctionId,auction));
}

void AuctionManager::placeBid(const std::string &auctionId,
		const std::shared_ptr<User> &user, double bidAmount)
{
	auto found= auctions.find(auctionId);

	if(found != auctions.end()) {

		found->second->placeBid(user,bidAmount);
	}
}

std::shared_ptr<User> AuctionManager::endAuction(const std::string &auctionId)
{
	std::shared_ptr<User> winner;
	auto found= auctions.find(auctionId);

		if(found != auctions.end()) {
			found->second->endAuction();
			winner=found->second->getHighestBidder();
			auctions.erase(auctionId);
		}
		return winner;
}

std::vector<std::shared_ptr<Auction> > AuctionManager::getActiveAuctions() const
{
	std::vector<std::shared_ptr<Auction>> activeAuctions;

	for(auto iter = auctions.begin() ; iter != auctions.end() ; ++iter) {
		activeAuctions.push_back((*iter).second);
	}

	return activeAuctions;

}
