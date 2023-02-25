//
// Created by Sean Gastinov on 25/02/23.
//
#define stringify( name ) # name
#include "Execution.h"
#include <utility>
Execution::Execution(const std::string& executionID, std::string stockID, double executionPrice, int executionQuantity)
        : executionID{"DONE-"+executionID}, executionQuantity{executionQuantity}, executionPrice{executionPrice}, stockID{std::move(stockID)}{
}
std::string Execution::getStockID() const {
    return stockID;
}
std::string Execution::getexecutionID() const {
    return executionID;
}


void Execution::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "Execution ID: " << executionID << std::endl;
    os << "Stock ID: " << stockID << std::endl;
    os << "Execution Price: " << executionPrice << std::endl;
    os << "Execution Quantity: " << executionQuantity << std::endl;
}