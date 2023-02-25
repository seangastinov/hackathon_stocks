//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_ACCOUNT_H
#define HACKATHON_STOCKS_ACCOUNT_H
#include <string>
#include "Order.h"
#include "I_Printable.h"
#include "BuyOrder.h"
#include "SellOrder.h"
#include <vector>
#include <memory>


class Account : public I_Printable{
    friend class SellOrder;
    friend class MarketSimulator;
private:
    int userID;
    std::string userName;
    double realizedBalance;
    double unrealizedBalance;
    std::vector<std::shared_ptr<BuyOrder>> buy_pends;
    std::vector<std::shared_ptr<SellOrder>> sell_pends;
public:
    Account(int userID, std::string userName, double realizedBalance);
    void print(std::ostream &os) const override;
    static void remove_pointer_acc( std::vector<std::shared_ptr<SellOrder>> &sellorders, const std::shared_ptr<SellOrder>& executed_order);
    static void remove_pointer_acc( std::vector<std::shared_ptr<BuyOrder>> &buyorders, const std::shared_ptr<BuyOrder>& executed_order);
    void updateBuyRealBalance(double price, int quantity);
    void updateSellRealBalance(double price, int quantity);
    ~Account() override = default;


};


#endif //HACKATHON_STOCKS_ACCOUNT_H
