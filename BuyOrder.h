//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_BUYORDER_H
#define HACKATHON_STOCKS_BUYORDER_H
#include "Order.h"

class BuyOrder: public Order {
private:
    constexpr static const OrderType def_orderType = OrderType::BUY;
protected:
    OrderType orderType;
public:
    BuyOrder(int orderID, std::string stockID, double orderPrice, int orderQuantity,OrderType orderType = def_orderType);
    OrderType getOrderType() override;
    void print(std::ostream &os) const override;
    ~BuyOrder() override= default;
};


#endif //HACKATHON_STOCKS_BUYORDER_H
