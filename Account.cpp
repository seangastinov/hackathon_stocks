//
// Created by Sean Gastinov on 25/02/23.
//

#include "Account.h"
#include <memory>
#include <utility>
#include <algorithm>
Account::Account(int userID,std::string name)
    : userID(userID), userName(std::move(name)) {}

void Account::addBuy(const std::shared_ptr<BuyOrder>& buy_order) {
    buy_log.emplace_back(buy_order);
}
void Account::addSell(const std::shared_ptr<SellOrder>& sell_order) {
    sell_log.emplace_back(sell_order);
}
std::string Account::getUsername() const {
    return userName;
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
    for (auto const& buy_pend : buy_log) {
        auto buy_order = buy_pend.lock();
        if (buy_order) {
            os << buy_order->getOrderID()<< " ";
            os << buy_order->getOrderPrice() << " ";
            os << buy_order->getOrderQuantity() << " " << "BUY";
            os << std::endl;
        }
    }
    os << "Current Sell Orders: " << std::endl;
    for (auto const& sell_pend : sell_log) {
        auto sell_order = sell_pend.lock();
        if (sell_order) {
            os << sell_order->getStockID() << " ";
            os << sell_order->getOrderPrice() << " ";
            os << sell_order->getOrderQuantity() << " " << "SELL";
            os << std::endl;
        }
    }
    os << std::endl;
}





