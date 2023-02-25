//
// Created by Sean Gastinov on 25/02/23.
//

#include "MarketSimulator.h"
#include <memory>
void MarketSimulator::addOrder(const std::string& StockID, int quantity, double price, OrderType orderType, Account &account) {
    if (orderType == OrderType::BUY && account.realizedBalance >= price * quantity && account.unrealizedBalance >= price * quantity) {
        std::shared_ptr<BuyOrder> temp = std::make_shared<BuyOrder>(account.userID, StockID, price, quantity); //CHECK
        buy_orders.push_back(temp);
        account.buy_pends.push_back(temp);
        account.unrealizedBalance = account.realizedBalance - price * quantity;
        std::cout << "Generated Buy Order - " << *temp << std::endl;
    } else if (orderType == OrderType::SELL) {
        std::shared_ptr<SellOrder> temp = std::make_shared<SellOrder>(account.userID, StockID, price, quantity);
        sell_orders.push_back(temp);
        account.sell_pends.push_back(temp);
        account.unrealizedBalance = account.realizedBalance + price * quantity;
        std::cout << "Generated Sell Order - " << *temp << std::endl;
    }
    else{
        std::cout << "Insufficient Funds" << std::endl;
    }
}

void MarketSimulator::remove_pointer(std::vector<std::shared_ptr<BuyOrder>> &buy_orders, const std::shared_ptr<BuyOrder>& executed_order){
    buy_orders.erase(std::remove(buy_orders.begin(), buy_orders.end(), executed_order), buy_orders.end());
}

void MarketSimulator::remove_pointer(std::vector<std::shared_ptr<SellOrder>> &sell_orders, const std::shared_ptr<SellOrder>& executed_order){
    sell_orders.erase(std::remove(sell_orders.begin(), sell_orders.end(), executed_order), sell_orders.end());
}
void MarketSimulator::addExecution(int quantity, double price, BuyOrder &buyOrder, SellOrder &sellOrder) {
    std::string ExecutionID = std::to_string(nextExecutionID++);
    std::unique_ptr<Execution> temp_buy = std::make_unique<Execution>(ExecutionID, quantity, price, buyOrder.getStockID(), buyOrder.getUserID());
    std::cout<< "Generated Execution BUY - " << *temp_buy << std::endl;
    executions.push_back(std::move(*temp_buy));
    std::unique_ptr<Execution> temp_sell = std::make_unique<Execution>(ExecutionID, quantity, price, sellOrder.getStockID(), sellOrder.getUserID());
    std::cout<< "Generated Execution SELL - " << *temp_sell << std::endl;
    executions.push_back(std::move(*temp_sell));
}


void matchingExecutions(std::vector<BuyOrder> &buy_orders, std::vector<SellOrder> &sell_orders){
//REMEMBER remove order from 2 vector

}