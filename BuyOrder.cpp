//
// Created by Sean Gastinov on 25/02/23.
//

#include "BuyOrder.h"

#include <utility>
BuyOrder::BuyOrder(int userID,const std::string stockID, double orderPrice, int orderQuantity, int orderID)
        : Order(userID, stockID, orderPrice, orderQuantity, orderID){
}
bool BuyOrder::operator<(const Order &rhs) const {
    if (this->orderPrice < rhs.getOrderPrice()){
        return true;
    }
    return false;
}
OrderType BuyOrder::getOrderType() {
    return orderType;
}

void BuyOrder::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "User ID: " << userID << std::endl;
    os << "Stock ID: " << stockID << std::endl;
    os << "Order Price: " << orderPrice << std::endl;
    os << "Order Quantity: " << orderQuantity << std::endl;
    os << "Order Type" << orderTypeStrings[orderType] << std::endl;
    os<< "Order ID: " << orderID << std::endl;
}