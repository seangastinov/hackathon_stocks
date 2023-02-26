//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_PRICELOTBUY_H
#define HACKATHON_STOCKS_PRICELOTBUY_H
class pricelotbuy{
    double price;
    int lot;
    int orderID;

    public:
    pricelotbuy(double price, int lot, int orderID )
        :price{price}, lot{lot}, orderID{orderID}{
    }
    bool operator<(const pricelotbuy& p2)const{
        if(this->price==p2.price){
            return this->orderID > p2.orderID;
        } else {
            return this->price < p2.price;}
        }
    void changePrice(double num) {
        price = num;
    }
    void changeLot(int num){
        lot = num;
    }
    void changeOrderID(int num){
        orderID = num;
    }
    int getOrderID_lotbuy()const{
        return orderID;
    }
};

#endif //HACKATHON_STOCKS_PRICELOTBUY_H
