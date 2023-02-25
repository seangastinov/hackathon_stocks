//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_PRICELOTSELL_H
#define HACKATHON_STOCKS_PRICELOTSELL_H
class pricelotsell{
    double price;
    int lot;
    int orderID;
    public:
    pricelotsell(double price, int lot, int orderID )
        :price{price}, lot{lot}, orderID{orderID}{
    }
    bool operator<(const pricelotsell& p2)const{
        if(this->price==p2.price){
            return this->orderID > p2.orderID;
        } else {
            return this->price > p2.price;
        }
    }
    int getOrderID_lotsell()const{
        return orderID;
    }
};
#endif //HACKATHON_STOCKS_PRICELOTSELL_H
