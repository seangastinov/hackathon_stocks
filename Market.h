//
// Created by Sean Gastinov on 12/03/23.
//

#ifndef HACKATHON_STOCKS_MARKET_H
#define HACKATHON_STOCKS_MARKET_H
#include <string>
#include <queue>
#include "Order.h"
#include "BuyOrder.h"
#include "SellOrder.h"
#include <memory>

struct ptr_less {
    template<class T>
    bool operator()(const T& left, const T& right) const {
        return ((*left) <( *right));
    }
};

class Market {
    std::string stockID;
    std::priority_queue<std::shared_ptr<BuyOrder>, std::vector<std::shared_ptr<BuyOrder>>, ptr_less> buy;
    std::priority_queue<std::shared_ptr<SellOrder>, std::vector<std::shared_ptr<SellOrder>>, ptr_less> sell;
public:
    Market() = default;
    Market(std::string stockID);
    bool checkBuyEmpty() const;
    bool checkSellEmpty() const;
    std::string getStockID() const;
    BuyOrder& getTopBuy() const;
    SellOrder& getTopSell() const;
    void addBuy(const std::shared_ptr<BuyOrder>& BuyOrder);
    void addSell(const std::shared_ptr<SellOrder>& SellOrder);
    void poppedBuy();
    void poppedSell();
};


#endif //HACKATHON_STOCKS_MARKET_H
