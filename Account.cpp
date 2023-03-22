//
// Created by Sean Gastinov on 25/02/23.
//

#include "Account.h"
#include <memory>
#include <utility>
#include <algorithm>
#include "BuyOrder.h"
#include "SellOrder.h"
Account::Account(int userID,std::string name)
    : userID(userID), userName(std::move(name)) {}

void Account::addBuy(const std::shared_ptr<BuyOrder>& buy_order) {
    buy_log.emplace_back(buy_order);
}
void Account::addSell(const std::shared_ptr<SellOrder>& sell_order) {
    sell_log.emplace_back(sell_order);
}

int Account::getUserID() const {
    return userID;
}
void Account::updateOrder() {
    buy_log.erase(std::remove_if(buy_log.begin(), buy_log.end(), [](const auto& wp) { return wp.expired(); }), buy_log.end());
    sell_log.erase(std::remove_if(sell_log.begin(), sell_log.end(), [](const auto& wp) { return wp.expired(); }), sell_log.end());
}

void Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "User ID: " << userID << std::endl;
    os << "User Name: " << userName << std::endl;
    os << "Current Buy Orders: " << std::endl;
    if (buy_log.empty()) {
        os << "No Buy Orders" << std::endl;
    }
    for (auto const& buy_pend : buy_log) {
        auto buy_order = buy_pend.lock();
        if (buy_order) {
            os << "Order ID:"<< buy_order->getOrderID()<< " ";
            os << "Stock ID:" << buy_order->getStockID() << " ";
            os << "Price:"<< buy_order->getOrderPrice() << " ";
            os << "Quantity:" << buy_order->getOrderQuantity();
            os << std::endl;
        }
    }
    os << "Current Sell Orders: " << std::endl;
    if (sell_log.empty()) {
        os << "No Sell Orders" << std::endl;
    }
    for (auto const& sell_pend : sell_log) {
        auto sell_order = sell_pend.lock();
        if (sell_order) {
            os << "Order ID:"<< sell_order->getOrderID()<< " ";
            os << "Stock ID:" << sell_order->getStockID() << " ";
            os << "Price:" << sell_order->getOrderPrice() << " ";
            os << "Quantity:"<< sell_order->getOrderQuantity();
            os << std::endl;
        }
    }
    os << std::endl;
}





