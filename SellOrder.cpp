//
// Created by Sean Gastinov on 25/02/23.
//

#include "SellOrder.h"

#include <utility>
SellOrder::SellOrder(Account &acc, std::string stockID, double orderPrice, int orderQuantity, int orderID)
        : Order(acc.getUserID(), std::move(stockID), orderPrice, orderQuantity, orderID), acc(acc){
}

bool SellOrder::operator<(const Order &rhs) const {
    if (this->orderPrice < rhs.getOrderPrice()){
        return false;
    }
    return true;
}
OrderType SellOrder::getOrderType() {
    return orderType;
}

Account& SellOrder::getAccount() const {
    return acc;
}

void SellOrder::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "User ID: " << userID << std::endl;
    //os << "Stock ID: " << stockID << std::endl;
    os << "Order Price: " << orderPrice << std::endl;
    os << "Order Quantity: " << orderQuantity << std::endl;
    os << "Order Type: "<< orderTypeStrings[orderType] << std::endl;
    os << "Order ID: " << orderID << std::endl;

}