//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_MARKETSIMULATOR_H
#define HACKATHON_STOCKS_MARKETSIMULATOR_H
#include "Order.h"
#include "SellOrder.h"
#include "BuyOrder.h"
#include "Execution.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Account.h"
#include <unordered_map>
#include <queue>

class Account;
struct company;

class MarketSimulator {
protected:
    int nextOrderID_Sell{1};
    int nextOrderID_Buy{1};
    int nextExecutionID{1};
    std::vector<std::shared_ptr<SellOrder>> sell_orders;
    std::vector<std::shared_ptr<BuyOrder>> buy_orders;
    std::vector<Execution> executions;
    std::unordered_map<std::string, company> companies;
    std::vector<std::string> comps;

public:
    MarketSimulator(std::unordered_map<std::string, company> comps_r,  std::vector<std::string> comp_r);
    void createCompanies(std::unordered_map<std::string, company> &comps, std::vector <std::string> &comp );
    void addOrder(const std::string& StockID, int quantity, double price, OrderType orderType,  Account &acc);
    void addExecution(int quantity, double price, BuyOrder &buyOrder, SellOrder &sellOrder);
    void matchingExecutions(std::vector<BuyOrder> &buy_orders, std::vector<SellOrder> &sell_orders);

};


#endif //HACKATHON_STOCKS_MARKETSIMULATOR_H
