//
// Created by Sean Gastinov on 25/02/23.
//


#include "Account.h"
Account::Account(int userID, std::string userName, double realizedBalance)
    : userID{userID}, userName{std::move(userName)}, realizedBalance{realizedBalance}{
}
void Account::remove_pointer_acc(std::vector<std::shared_ptr<SellOrder>> &sellorders, const std::shared_ptr<SellOrder>& executed_order){
    sellorders.erase(std::remove(sellorders.begin(), sellorders.end(), executed_order), sellorders.end());
}

void Account::remove_pointer_acc(std::vector<std::shared_ptr<BuyOrder>> &buyorders, const std::shared_ptr<BuyOrder>& executed_order){
    buyorders.erase(std::remove(buyorders.begin(), buyorders.end(), executed_order), buyorders.end());
}
void Account::updateBuyRealBalance(double price, int quantity){
    realizedBalance -= price * quantity;
}
void Account::updateSellRealBalance(double price, int quantity){
    realizedBalance += price * quantity;
}

void Account::print(std::ostream &os) const{
    os.precision(2);
    os << std::fixed;
    os << "User ID: " << userID << std::endl;
    os << "User Name: " << userName << std::endl;
    os << "Realized Balance: " << realizedBalance << std::endl;
}

