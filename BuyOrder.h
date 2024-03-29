//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_BUYORDER_H
#define HACKATHON_STOCKS_BUYORDER_H
#include "Order.h"
#include "Account.h"

class BuyOrder: public Order{

    friend class Account;
private:
    constexpr static const OrderType def_orderType =BUY;
protected:
    OrderType orderType = def_orderType;
    Account &acc;
public:
    BuyOrder(Account &acc,std::string stockID, double orderPrice, int orderQuantity, int orderID);
    bool operator<(const Order &rhs) const;
    OrderType getOrderType() override;
    Account& getAccount() const;
    void print(std::ostream &os) const override;
    ~BuyOrder() override= default;
};


#endif //HACKATHON_STOCKS_BUYORDER_H
