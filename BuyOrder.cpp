//
// Created by Sean Gastinov on 25/02/23.
//

#include "BuyOrder.h"

#include <utility>
BuyOrder::BuyOrder(int orderID, std::string stockID, double orderPrice, int orderQuantity)
        : Order(orderID, std::move(stockID), orderPrice, orderQuantity){
}

OrderType BuyOrder::getOrderType() {
    return orderType;
}

void BuyOrder::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "Order ID: " << orderID << std::endl;
    os << "Stock ID: " << stockID << std::endl;
    os << "Order Price: " << orderPrice << std::endl;
    os << "Order Quantity: " << orderQuantity << std::endl;
    os << "Order Type" << orderTypeStrings[orderType] << std::endl;
}