//
// Created by Sean Gastinov on 25/02/23.
//
#define stringify( name ) # name
#include "Execution.h"

#include <utility>
Execution::Execution(const std::string& executionID, int executionQuantity, double executionPrice,std::string stockID, int orderID)
        : executionID{"DONE-"+executionID}, executionQuantity{executionQuantity}, executionPrice{executionPrice}, stockID{std::move(stockID)}, orderID{orderID}{
}
std::string Execution::getStockID() const {
    return stockID;
}
std::string Execution::getOrderID() const {
    return std::to_string(orderID);
}


void Execution::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "Execution ID: " << executionID << std::endl;
    os << "Execution Quantity: " << executionQuantity << std::endl;
    os << "Execution Price: " << executionPrice << std::endl;
    os << "Stock ID: " << stockID << std::endl;
    os << "Order ID: " << orderID << std::endl;
}