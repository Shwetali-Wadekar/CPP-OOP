/*
 * Auction.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "Auction.h"

Auction::Auction(const std::string &auctionId,
		const std::shared_ptr<Item> &item) : auctionId(auctionId) , item(item)
{
	highestBid=0;
}

void Auction::placeBid(const std::shared_ptr<User> &user, double bidAmount)
{
	bool flag=false;

	for(auto iter = bidders.begin() ; iter != bidders.end() ; ++iter) {
		if( (**iter).getUserRole()=="Buyer") {
			if((**iter).getUserId()==user->getUserId()) {
				flag=true;
			}
		}
	}

	if(!flag) {
		bidders.push_back(user);

	}

	if(user->getUserRole()=="Buyer") {
		if(bidAmount>highestBid && bidAmount > item->getStartingPrice() && bidAmount<=user->getBalance()) {
			this->highestBid=bidAmount;
			this->highestBidder=user;
		}
	}

}

double Auction::getHighestBid() const
{
	return this->highestBid;
}

std::shared_ptr<User> Auction::getHighestBidder() const
{
	return this->highestBidder;
}

std::shared_ptr<Poco::JSON::Object> Auction::toJson() const
{
	std::shared_ptr<Poco::JSON::Object> jsonPtr(new Poco::JSON::Object);
	Poco::JSON::Object itemObj=*item->toJson().get();

	jsonPtr->set("item", itemObj);
	jsonPtr->set("auctionID",auctionId);
	return jsonPtr;
}

const std::string& Auction::getAuctionId() const
{
	return auctionId;
}

std::shared_ptr<User> Auction::endAuction()
{
	auto remainingBalance= highestBidder->getBalance() - this->highestBid;
	highestBidder->updateBalance(remainingBalance);
	return this->highestBidder;

}
