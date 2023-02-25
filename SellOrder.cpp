//
// Created by Sean Gastinov on 25/02/23.
//

#include "SellOrder.h"
#include "Account.h"

#include <utility>
SellOrder::SellOrder(Account &acc, std::string stockID, double orderPrice, int orderQuantity)
        : Order(std::move(stockID), orderPrice, orderQuantity), Account (acc) {
}

OrderType SellOrder::getOrderType() {
    return orderType;
}

void SellOrder::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "User ID: " << userID << std::endl;
    os << "Stock ID: " << stockID << std::endl;
    os << "Order Price: " << orderPrice << std::endl;
    os << "Order Quantity: " << orderQuantity << std::endl;
    os << "Order Type: "<< orderTypeStrings[orderType] << std::endl;
}