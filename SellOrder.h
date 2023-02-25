//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_SELLORDER_H
#define HACKATHON_STOCKS_SELLORDER_H
#include "Order.h"
#include "Account.h"

class SellOrder: public Order {
    friend class MarketSimulator;
private:
    constexpr static const OrderType def_orderType = SELL;
protected
    OrderType orderType = def_orderType;
    Account acc;
public:
    SellOrder(Account &acc, std::string stockID, double orderPrice, int orderQuantity);
    OrderType getOrderType() override;
    int getUserID() override;
    void print(std::ostream &os) const override;
    virtual ~SellOrder() = default;
};


#endif //HACKATHON_STOCKS_SELLORDER_H
