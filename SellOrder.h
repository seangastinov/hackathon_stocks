//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_SELLORDER_H
#define HACKATHON_STOCKS_SELLORDER_H
#include "Order.h"
#include "Account.h"

class SellOrder: public Order  {
    friend class Account;
private:
    constexpr static const OrderType def_orderType = SELL;
protected:
    OrderType orderType = def_orderType;
    Account acc;

public:
    bool operator<(const Order &rhs) const;
    SellOrder(int userID, const std::string& stockID, double orderPrice, int orderQuantity, int orderID);
    OrderType getOrderType() override;
    void print(std::ostream &os) const override;
    virtual ~SellOrder() = default;
};


#endif //HACKATHON_STOCKS_SELLORDER_H
