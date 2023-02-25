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

class MarketSimulator {
protected:
    int nextOrderID_Sell{1};
    int nextOrderID_Buy{1};
    int nextExecutionID{1};
    std::vector<SellOrder> sell_orders;
    std::vector<BuyOrder> buy_orders;
    std::vector<Execution> executions;

public:
    void addOrder(const std::string& StockID, int quantity, double price, OrderType orderType);
    void addExecution(int quantity, double price, BuyOrder &buyOrder, SellOrder &sellOrder);
    void matchingExecutions(std::vector<BuyOrder> &buy_orders, std::vector<SellOrder> &sell_orders);
};


#endif //HACKATHON_STOCKS_MARKETSIMULATOR_H
