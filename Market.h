//
// Created by Sean Gastinov on 12/03/23.
//

#ifndef HACKATHON_STOCKS_MARKET_H
#define HACKATHON_STOCKS_MARKET_H
#include <string>
#include <queue>
#include "BuyOrder.h"
#include "SellOrder.h"
#include <memory>

class Market {
    std::string stockID;
    std::priority_queue<std::shared_ptr<BuyOrder>> buy;
    std::priority_queue<std::shared_ptr<SellOrder>> sell;
public:
    Market() = default;
    Market(std::string stockID);
    bool checkBuyEmpty() const;
    bool checkSellEmpty() const;
    std::string getStockID() const;
    BuyOrder& getTopBuy() const;
    SellOrder& getTopSell() const;
    void addBuy(const std::shared_ptr<BuyOrder>& BuyOrder);
    void addSell(const std::shared_ptr<SellOrder>&  SellOrder);
    void poppedBuy();
    void poppedSell();
};


#endif //HACKATHON_STOCKS_MARKET_H
