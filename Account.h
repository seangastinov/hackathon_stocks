//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_ACCOUNT_H
#define HACKATHON_STOCKS_ACCOUNT_H
#include "I_Printable.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

class BuyOrder;
class SellOrder;

class Account : public I_Printable{
    friend class BuyOrder;
    friend class SellOrder;
    protected:
    int userID;
    std::string userName;
    std::vector<std::weak_ptr<BuyOrder>> buy_log;
    std::vector<std::weak_ptr<SellOrder>> sell_log;

    public:

    Account(int userID, std::string userName);
    void addBuy (const std::shared_ptr<BuyOrder>& buy_order);
    void addSell (const std::shared_ptr<SellOrder>& sell_order);
    int getUserID() const;
    void print(std::ostream &os) const override;
    void updateOrder();
    ~Account() override = default;
};


#endif //HACKATHON_STOCKS_ACCOUNT_H
