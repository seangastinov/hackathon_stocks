//
// Created by Sean Gastinov on 25/02/23.
//

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "pricelotbuy.h"
#include "pricelotsell.h"
#include "MarketSimulator.h"
using namespace std;


void MarketSimulator::createCompanies(std::unordered_map<std::string, company> &comps, std::vector <std::string> &datas ){
    for (const auto &name: datas) {
        build(name, comps);
    }
}

MarketSimulator::MarketSimulator(){
    // Extracting values from csv and storing into a vector
    ifstream file("stock_names.csv");
    vector<string> data1D; // Declare a 1D vector to store the contents

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string field;

        while (getline(ss, field, ',')) {
            data1D.push_back(field);
        }
    }

    file.close(); // Close the file
    createCompanies(companies, data1D);

}
//void MarketSimulator::addOrder(const std::string& StockID, int quantity, double price, OrderType orderType,  Account &acc) {
//    if (orderType == OrderType::BUY) {
//        std::shared_ptr<BuyOrder> temp = std::make_shared<BuyOrder>(acc.userID, StockID, price, quantity, nextOrderID_Buy++); //CHECK
//        buy_orders.push_back(temp);
//        acc.addBuy(temp);
//        std::cout << "Generated Buy Order - " << *temp << std::endl;
//    } else if (orderType == OrderType::SELL) {
//        std::shared_ptr<SellOrder> temp = std::make_shared<SellOrder>(acc.userID, StockID, price, quantity, nextOrderID_Sell++);
//        sell_orders.push_back(temp);
//        acc.addSell(temp);
//        std::cout << "Generated Sell Order - " << *temp << std::endl;
//    }
//}

void MarketSimulator::addExecution(int quantity, double price, BuyOrder &buyOrder, SellOrder &sellOrder) {
    std::string ExecutionID = std::to_string(nextExecutionID++);
    std::unique_ptr<Execution> temp_buy = std::make_unique<Execution>(ExecutionID,buyOrder.getStockID(), price, quantity );
    std::cout<< "Generated Execution BUY - " << *temp_buy << std::endl;
    executions.push_back(std::move(*temp_buy));
    buy_orders.erase(buy_orders.begin()+ buyOrder.getOrderID());
    std::unique_ptr<Execution> temp_sell = std::make_unique<Execution>(ExecutionID,sellOrder.getStockID(), price, quantity);
    std::cout<< "Generated Execution SELL - " << *temp_sell << std::endl;
    executions.push_back(std::move(*temp_sell));
    sell_orders.erase(sell_orders.begin()+ sellOrder.getOrderID());

}
void MarketSimulator::build(std::string name, std::unordered_map<std::string, company> &companies) {
    company temp;
    companies[name] = temp;
}

void MarketSimulator::matchingExecutions(int orderTypeInt, double price, int lotAmt, std::string compID){
    //need to check buy or sell is 0 or 1
    if(orderTypeInt==0) {
        pricelotbuy temp(price, lotAmt, nextOrderID_Buy++);
        companies[compID].buy.push(temp);
    }
    else if(orderTypeInt==1){
        pricelotsell temp(price, lotAmt, nextOrderID_Sell++);
        companies[compID].sell.push(temp);
    }

//    while(!companies[compID].buy.empty() && !companies[compID].sell.empty()){
//        if(companies[compID].buy.top().price >= companies[compID].sell.top().price){
//            int lot = min(companies[compID].buy.top().lotAmt, companies[compID].sell.top().lotAmt);
//            addExecution(lot, companies[compID].buy.top().price, companies[compID].buy.top().orderID, companies[compID].sell.top().orderID);
//            companies[compID].buy.pop();
//            companies[compID].sell.pop();
//        }
//        else{
//            break;
//        }
//    }
}
