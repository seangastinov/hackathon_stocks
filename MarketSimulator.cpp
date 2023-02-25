//
// Created by Sean Gastinov on 25/02/23.
//

#include "MarketSimulator.h"
#include <memory>


void MarketSimulator::addOrder(const std::string& StockID, int quantity, double price, OrderType orderType,  Account &acc) {
    if (orderType == OrderType::BUY) {
        std::shared_ptr<BuyOrder> temp = std::make_shared<BuyOrder>(acc.userID, StockID, price, quantity, nextOrderID_Buy++); //CHECK
        buy_orders.push_back(temp);
        acc.addBuy(temp);
        std::cout << "Generated Buy Order - " << *temp << std::endl;
    } else if (orderType == OrderType::SELL) {
        std::shared_ptr<SellOrder> temp = std::make_shared<SellOrder>(acc.userID, StockID, price, quantity, nextOrderID_Buy++);
        sell_orders.push_back(temp);
        acc.addSell(temp);
        std::cout << "Generated Sell Order - " << *temp << std::endl;
    }
}

void MarketSimulator::addExecution(int quantity, double price, BuyOrder &buyOrder, SellOrder &sellOrder) {
    std::string ExecutionID = std::to_string(nextExecutionID++);
    std::unique_ptr<Execution> temp_buy = std::make_unique<Execution>(ExecutionID,buyOrder.getStockID(), price, quantity );
    std::cout<< "Generated Execution BUY - " << *temp_buy << std::endl;
    executions.push_back(std::move(*temp_buy));
    buy_orders.erase(buy_orders.begin()+ buyOrder.getOrderID());
    std::unique_ptr<Execution> temp_sell = std::make_unique<Execution>(ExecutionID,buyOrder.getStockID(), price, quantity);
    std::cout<< "Generated Execution SELL - " << *temp_sell << std::endl;
    executions.push_back(std::move(*temp_sell));
    buy_orders.erase(buy_orders.begin()+ buyOrder.getOrderID());

}


void matchingExecutions(std::vector<BuyOrder> &buy_orders, std::vector<SellOrder> &sell_orders){


}