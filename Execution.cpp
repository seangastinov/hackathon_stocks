//
// Created by Sean Gastinov on 25/02/23.
//
#include "Execution.h"
#include <utility>
#include <cmath>
Execution::Execution(const BuyOrder& buyOrder, const SellOrder& sellOrder, int executionQuantity, int executionID)
        : executionID{executionID}, executionQuantity{executionQuantity}, stockID{buyOrder.getStockID()}, profit{std::abs(executionQuantity*(sellOrder.getOrderPrice() - buyOrder.getOrderPrice()))} {
    std::cout << "Execution created" << std::endl;
}
std::string Execution::getStockID() const {
    return stockID;
}

int Execution::getexecutionID() const {
    return executionID;
}


void Execution::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "Execution ID: " << executionID << std::endl;
    os << "Stock ID: " << stockID << std::endl;
    os << "Execution Profit: " << profit  << std::endl;
    os << "Execution Quantity: " << executionQuantity << std::endl;
}