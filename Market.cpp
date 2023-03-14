//
// Created by Sean Gastinov on 12/03/23.
//

#include "Market.h"

#include <utility>
Market::Market(std::string stockID) : stockID(std::move(stockID)){}
std::string Market::getStockID() const {
    return stockID;
}
BuyOrder& Market::getTopBuy() const{
    return *(buy.top());
}
SellOrder& Market::getTopSell() const{
    return *(sell.top());
}
void Market::addBuy(const std::shared_ptr<BuyOrder>& buyOrder) {
    buy.push(buyOrder);
}
void Market::addSell(const std::shared_ptr<SellOrder>& sellOrder) {
    sell.push(sellOrder);
}

void Market::poppedBuy() {
    buy.pop();
}
void Market::poppedSell() {
    sell.pop();
}
bool Market::checkBuyEmpty() const {
    return buy.empty();
}
bool Market::checkSellEmpty() const {
    return sell.empty();
}