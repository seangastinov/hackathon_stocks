//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_ORDER_H
#define HACKATHON_STOCKS_ORDER_H
#include <string>
#include <vector>
#include <iostream>
#include "I_Printable.h"
#include "Account.h"

enum OrderType {BUY, SELL};
class Account;
static const std::string orderTypeStrings[] = {"BUY", "SELL"};
class Order: public I_Printable, public Account {
    friend Account;
protected:
    Account &acc;
    int orderID;
    int orderQuantity;
    int userID;
    std::string stockID;
    double orderPrice;
public:
    Order(Account& acc, std::string stockID, double orderPrice, int orderQuantity, int orderID); //constructor
    //Order(const Order &source); //copy constructor idk perlu ato ga just in case
    int getOrderQuantity();
    Account &getAccount() const;
    int getOrderID() const;
    double getOrderPrice() const;
    void changeOrderQuantity(int newQuantity);
    std::string getStockID() const;
    virtual OrderType getOrderType()=0;
    void print(std::ostream &os) const override;
    ~Order() override =default;
};


#endif //HACKATHON_STOCKS_ORDER_H
