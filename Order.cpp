//
// Created by Sean Gastinov on 25/02/23.
//

#include "Order.h"
#include "Account.h"

#include <utility>

Order::Order( std::string stockID, double orderPrice, int orderQuantity)
        :stockID(std::move(stockID)), orderQuantity{orderQuantity}, orderPrice{orderPrice} {
}

int Order::getOrderQuantity(){
    return orderQuantity;
}

double Order::getOrderPrice() const{
    return orderPrice;
}

std::string Order::getStockID() {
    return stockID;
}



void Order::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "Stock ID: " << stockID << std::endl;
    os << "Order Price: " << orderPrice << std::endl;
    os << "Order Quantity: " << orderQuantity << std::endl;
}