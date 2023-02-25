//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_ORDER_H
#define HACKATHON_STOCKS_ORDER_H
#include <string>
#include <vector>
#include <iostream>
#include "I_Printable.h"

enum OrderType {BUY, SELL};
static const std::string orderTypeStrings[] = {"BUY", "SELL"};

class Order: public I_Printable {
protected:
    int orderID;
    int orderQuantity;
    std::string stockID;
    double orderPrice;
public:
    Order(int orderID, std::string stockID, double orderPrice, int orderQuantity); //constructor
    //Order(const Order &source); //copy constructor idk perlu ato ga just in case
    int getOrderID() const;
    int getOrderQuantity();
    double getOrderPrice() const;
    std::string getStockID();
    virtual OrderType getOrderType()=0;
    void print(std::ostream &os) const override;
    ~Order() override =default;
};


#endif //HACKATHON_STOCKS_ORDER_H
