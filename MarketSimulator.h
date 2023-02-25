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
#include <string>
#include <iostream>
#include <memory>
#include "Account.h"    // for Account

class MarketSimulator {
    friend class account;

protected:
    int nextOrderID_Sell{1};
    int nextOrderID_Buy{1};
    int nextExecutionID{1};
    std::vector<std::shared_ptr<SellOrder>> sell_orders;
    std::vector<std::shared_ptr<BuyOrder>> buy_orders;
    std::vector<Execution> executions;

public:
    void addOrder(const std::string& StockID, int quantity, double price, OrderType orderType, Account &account);
    void addExecution(int quantity, double price, BuyOrder &buyOrder, SellOrder &sellOrder);
    static void remove_pointer(std::vector<std::shared_ptr<BuyOrder>> &buy_orders, const std::shared_ptr<BuyOrder>& executed_order);
    static void remove_pointer(std::vector<std::shared_ptr<SellOrder>> &sell_orders, const std::shared_ptr<SellOrder>& executed_order);
    void matchingExecutions(std::vector<BuyOrder> &buy_orders, std::vector<SellOrder> &sell_orders);
};


#endif //HACKATHON_STOCKS_MARKETSIMULATOR_H
