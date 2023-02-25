//
// Created by Sean Gastinov on 25/02/23.
//

#include "Account.h"

#include <utility>
Account::Account(int userID,std::string name)
    : userID(userID), userName(std::move(name)) {}

void Account::addBuy(std::shared_ptr<BuyOrder> buy_order) {
    buy_log.push_back(buy_order);
}
void Account::addSell(std::shared_ptr<SellOrder> sell_order) {
    sell_log.push_back(sell_order);
}

void Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "User ID: " << userID << std::endl;
    os << "User Name: " << userName << std::endl;
    os << "Buy Orders: ";
    for (auto &buy_pend : buy_log) {
        os << buy_pend->getStockID() << " ";
        os << buy_pend->getOrderPrice() << " ";
        os << buy_pend->getOrderQuantity() << " " << "BUY";
        os << std::endl;
    }
    os << "Sell Orders: ";
    for (auto &sell_pend : sell_log) {
        os << sell_pend->getStockID() << " ";
        os << sell_pend->getOrderPrice() << " ";
        os << sell_pend->getOrderQuantity() << " " << "SELL";
        os << std::endl;
    }
}