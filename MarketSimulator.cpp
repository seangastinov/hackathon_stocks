//
// Created by Sean Gastinov on 25/02/23.
//

#include "MarketSimulator.h"
#include <memory>
void MarketSimulator::addOrder(const std::string& StockID, int quantity, double price, OrderType orderType) {
    if (orderType == OrderType::BUY) {
        std::unique_ptr<BuyOrder> temp = std::make_unique<BuyOrder>(nextOrderID_Buy++, StockID, price, quantity); //CHECK
        buy_orders.push_back(std::move(*temp));
        std::cout << "Generated Buy Order - " << *temp << std::endl;
    } else if (orderType == OrderType::SELL) {
        std::unique_ptr<SellOrder> temp = std::make_unique<SellOrder>(nextOrderID_Sell++, StockID, price, quantity);
        sell_orders.push_back(std::move(*temp));
        std::cout << "Generated Sell Order - " << *temp << std::endl;
    }
}

void MarketSimulator::addExecution(int quantity, double price, BuyOrder &buyOrder, SellOrder &sellOrder) {
    std::string ExecutionID = std::to_string(nextExecutionID++);
    std::unique_ptr<Execution> temp_buy = std::make_unique<Execution>(ExecutionID, quantity, price, buyOrder.getStockID(), buyOrder.getOrderID());
    std::cout<< "Generated Execution BUY - " << *temp_buy << std::endl;
    executions.push_back(std::move(*temp_buy));
    std::unique_ptr<Execution> temp_sell = std::make_unique<Execution>(ExecutionID, quantity, price, sellOrder.getStockID(), sellOrder.getOrderID());
    std::cout<< "Generated Execution SELL - " << *temp_sell << std::endl;
    executions.push_back(std::move(*temp_sell));
}


void matchingExecutions(std::vector<BuyOrder> &buy_orders, std::vector<SellOrder> &sell_orders){


}