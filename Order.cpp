//
// Created by Sean Gastinov on 25/02/23.
//

#include "Order.h"

#include <utility>

Order::Order(Account &acc, std::string stockID, double orderPrice, int orderQuantity, int orderID)
        :stockID(std::move(stockID)), orderQuantity{orderQuantity}, orderPrice{orderPrice}, acc{acc}, orderID{orderID} {
    userID= acc.getUserID();
}


int Order::getOrderQuantity(){
    return orderQuantity;
}

int Order::getOrderID() const{
    return orderID;
}
double Order::getOrderPrice() const{
    return orderPrice;
}

std::string Order::getStockID() const {
    return stockID;
}

void Order::changeOrderQuantity(int newQuantity) {
    orderQuantity = newQuantity;
}

Account& Order::getAccount() const {
    return acc;
}

void Order::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "User ID: " << userID << std::endl;
    os << "Username: " << acc.getUsername() << std::endl;
    os << "Stock ID: " << stockID << std::endl;
    os << "Order Price: " << orderPrice << std::endl;
    os << "Order Quantity: " << orderQuantity << std::endl;
}