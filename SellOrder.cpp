//
// Created by Sean Gastinov on 25/02/23.
//

#include "SellOrder.h"

#include <utility>
SellOrder::SellOrder(int orderID, std::string stockID, double orderPrice, int orderQuantity, OrderType orderType)
        : Order(orderID, std::move(stockID), orderPrice, orderQuantity), orderType{orderType} {
}

OrderType SellOrder::getOrderType() {
    return orderType;
}

void SellOrder::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "Order ID: " << orderID << std::endl;
    os << "Stock ID: " << stockID << std::endl;
    os << "Order Price: " << orderPrice << std::endl;
    os << "Order Quantity: " << orderQuantity << std::endl;
    os << "Order Type: "<< orderTypeStrings[orderType] << std::endl;
}