//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_ACCOUNT_H
#define HACKATHON_STOCKS_ACCOUNT_H
#include "I_Printable.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Order.h"
#include "BuyOrder.h"
#include "SellOrder.h"
#include "MarketSimulator.h"

class Account : public I_Printable{
    friend class MarketSimulator;
    protected:
    int userID;
    std::string userName;
    std::vector<std::shared_ptr<BuyOrder>> buy_log;
    std::vector<std::shared_ptr<SellOrder>> sell_log;

    public:
    Account(int userID, std::string userName);
    void addBuy (std::shared_ptr<BuyOrder> buy_order);
    void addSell (std::shared_ptr<SellOrder> sell_order);
    void print(std::ostream &os) const override;
    ~Account() override = default;
};


#endif //HACKATHON_STOCKS_ACCOUNT_H
