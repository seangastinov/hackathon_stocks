//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_MARKETSIMULATOR_H
#define HACKATHON_STOCKS_MARKETSIMULATOR_H
#include "Market.h"
#include "Order.h"
#include "SellOrder.h"
#include "BuyOrder.h"
#include "Execution.h"
#include "Account.h"
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>
class Account;
class MarketSimulator {
protected:
    std::unordered_map<std::string, Market> allMarkets{};
    int nextOrderID_Sell{1};
    int nextOrderID_Buy{1};
    int nextExecutionID{1};
    std::vector<Execution> executions;

public:
    MarketSimulator();
    void createCompanies(std::vector <std::string> &datas );
    void addOrder(const std::string& StockID, int quantity, double price, OrderType orderType, Account &acc);
};

#endif //HACKATHON_STOCKS_MARKETSIMULATOR_H
