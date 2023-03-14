//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_SELLORDER_H
#define HACKATHON_STOCKS_SELLORDER_H
#include "Order.h"
#include "Account.h"

class SellOrder: public Order{
private:
    constexpr static const OrderType def_orderType = SELL;
protected:
    OrderType orderType = def_orderType;
public:
    SellOrder(Account &acc,const std::string& stockID, double orderPrice, int orderQuantity, int orderID);
    bool operator<(const Order &rhs) const;
    OrderType getOrderType() override;
    void print(std::ostream &os) const override;

//    double getOrderPrice() const override;


    ~SellOrder() override = default;
};


#endif //HACKATHON_STOCKS_SELLORDER_H
