//
// Created by Sean Gastinov on 25/02/23.
//

#include <fstream>
#include <sstream>
#include <vector>
#include "MarketSimulator.h"
#include "Account.h"
using namespace std;


void MarketSimulator::createCompanies(std::vector <std::string> &datas ){
    for (const auto &name: datas) {
        allMarkets.insert({name,Market(name)});
    }
}

MarketSimulator::MarketSimulator(){
    // Extracting values from csv and storing into a vector
    ifstream file("stock_names.csv");
    std::vector<std::string> datas;
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string data;
        while (getline(ss, data, ',')) {
            datas.push_back(data);
        }
    }
    file.close(); // Close the file
    createCompanies(datas);
}

void MarketSimulator::addOrder(const std::string &StockID, int quantity, double price, OrderType orderType, Account &acc) {
    if (quantity <= 0)
        throw std::invalid_argument("Invalid quantity");
    else if (price <= 0)
        throw std::invalid_argument("Invalid quantity");


    if (orderType == SELL) {
        std::shared_ptr<SellOrder> selltemp = make_shared<SellOrder>(
                SellOrder(acc.getUserID(), StockID, price, quantity, nextOrderID_Sell++));
        allMarkets[StockID].addSell(selltemp);
        acc.addSell(selltemp);
        if (allMarkets[StockID].checkBuyEmpty() || allMarkets[StockID].getTopBuy().getOrderPrice() < price) {
        } else {
            if (allMarkets[StockID].getTopBuy().getOrderQuantity() == quantity) {
                executions.emplace_back(
                        Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(), quantity,nextExecutionID));
                allMarkets[StockID].poppedBuy();
                allMarkets[StockID].poppedSell();
                std::cout << executions[nextExecutionID - 1] << std::endl;
                nextExecutionID++;
            } else if (allMarkets[StockID].getTopBuy().getOrderQuantity() > quantity) {
                executions.emplace_back(
                        Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(), quantity,
                                  nextExecutionID));
                allMarkets[StockID].poppedSell();
                allMarkets[StockID].getTopBuy().changeOrderQuantity(
                        allMarkets[StockID].getTopBuy().getOrderQuantity() - quantity);
                std::cout << executions[nextExecutionID - 1] << std::endl;
                nextExecutionID++;
            } else if (allMarkets[StockID].getTopBuy().getOrderQuantity() < quantity) {
                executions.emplace_back(Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(),
                                                  allMarkets[StockID].getTopBuy().getOrderQuantity(), nextExecutionID));
                int newqty = quantity - allMarkets[StockID].getTopBuy().getOrderQuantity();
                allMarkets[StockID].getTopSell().changeOrderQuantity(newqty);
                allMarkets[StockID].poppedBuy();

                std::cout << executions[nextExecutionID - 1] << std::endl;
                nextExecutionID++;
                while (newqty != 0 && !allMarkets[StockID].checkBuyEmpty() && allMarkets[StockID].getTopSell().getOrderPrice() >= price) {
                    if (newqty > allMarkets[StockID].getTopBuy().getOrderQuantity()) {
                        executions.emplace_back(Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(),
                                          allMarkets[StockID].getTopBuy().getOrderQuantity(), nextExecutionID));
                        newqty -= allMarkets[StockID].getTopBuy().getOrderQuantity();
                        allMarkets[StockID].getTopSell().changeOrderQuantity(newqty);
                        allMarkets[StockID].poppedBuy();
                        std::cout << executions[nextExecutionID - 1] << std::endl;
                        nextExecutionID++;
                    } else if (newqty < allMarkets[StockID].getTopBuy().getOrderQuantity()) {
                        executions.emplace_back(
                                Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(), newqty,
                                          nextExecutionID));
                        allMarkets[StockID].getTopBuy().changeOrderQuantity(
                                allMarkets[StockID].getTopBuy().getOrderQuantity() - newqty);
                        std::cout << executions[nextExecutionID - 1] << std::endl;
                        allMarkets[StockID].poppedSell();
                        nextExecutionID++;
                        newqty = 0;
                    } else if (newqty == allMarkets[StockID].getTopBuy().getOrderQuantity()) {
                        executions.emplace_back(
                                Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(), newqty,
                                          nextExecutionID));
                        allMarkets[StockID].poppedBuy();
                        allMarkets[StockID].poppedSell();
                        std::cout << executions[nextExecutionID - 1] << std::endl;
                        nextExecutionID++;
                        newqty = 0;
                    }
                }
            }
        }
    } else if (orderType == BUY) {
        std::shared_ptr<BuyOrder> buytemp = make_shared<BuyOrder>(
                BuyOrder(acc.getUserID(), StockID, price, quantity, nextOrderID_Buy++));
        allMarkets[StockID].addBuy(buytemp);
        acc.addBuy(buytemp);
        if (allMarkets[StockID].checkSellEmpty() || allMarkets[StockID].getTopSell().getOrderPrice() > price) {
        } else {
            if (allMarkets[StockID].getTopSell().getOrderQuantity() == quantity) {
                executions.emplace_back(
                        Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(), quantity,
                                  nextExecutionID));
                allMarkets[StockID].poppedBuy();
                allMarkets[StockID].poppedSell();
                std::cout << executions[nextExecutionID - 1] << std::endl;
                nextExecutionID++;
            } else if (allMarkets[StockID].getTopSell().getOrderQuantity() > quantity) {
                executions.emplace_back(
                        Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(), quantity,
                                  nextExecutionID));
                allMarkets[StockID].poppedBuy();
                allMarkets[StockID].getTopSell().changeOrderQuantity(
                        allMarkets[StockID].getTopSell().getOrderQuantity() - quantity);
                std::cout << executions[nextExecutionID - 1] << std::endl;
                nextExecutionID++;
            } else if (allMarkets[StockID].getTopSell().getOrderQuantity() < quantity) {
                executions.emplace_back(Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(),
                                                  allMarkets[StockID].getTopSell().getOrderQuantity(),
                                                  nextExecutionID));
                int newqty = quantity - allMarkets[StockID].getTopSell().getOrderQuantity();
                allMarkets[StockID].getTopBuy().changeOrderQuantity(newqty);
                allMarkets[StockID].poppedSell();
                std::cout << executions[nextExecutionID - 1] << std::endl;
                nextExecutionID++;
                while (newqty != 0 && allMarkets[StockID].getTopSell().getOrderPrice() <= price) {
                    if (newqty > allMarkets[StockID].getTopSell().getOrderQuantity()) {
                        executions.emplace_back(Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(),
                                                          allMarkets[StockID].getTopSell().getOrderQuantity(),
                                                          nextExecutionID));
                        newqty -= allMarkets[StockID].getTopSell().getOrderQuantity();
                        allMarkets[StockID].getTopBuy().changeOrderQuantity(newqty);
                        allMarkets[StockID].poppedSell();
                        std::cout << executions[nextExecutionID - 1] << std::endl;
                        nextExecutionID++;
                    } else if (newqty < allMarkets[StockID].getTopSell().getOrderQuantity()) {
                        executions.emplace_back(
                                Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(), newqty,
                                          nextExecutionID));
                        allMarkets[StockID].getTopSell().changeOrderQuantity(
                                allMarkets[StockID].getTopSell().getOrderQuantity() - newqty);
                        std::cout << executions[nextExecutionID - 1] << std::endl;
                        allMarkets[StockID].poppedBuy();
                        nextExecutionID++;
                        newqty = 0;
                    } else if (newqty == allMarkets[StockID].getTopSell().getOrderQuantity()) {
                        executions.emplace_back(
                                Execution(allMarkets[StockID].getTopBuy(), allMarkets[StockID].getTopSell(), newqty,
                                          nextExecutionID));
                        allMarkets[StockID].poppedBuy();
                        allMarkets[StockID].poppedSell();
                        std::cout << executions[nextExecutionID - 1] << std::endl;
                        nextExecutionID++;
                        newqty = 0;
                    }
                }
            }
        }
    }
}
