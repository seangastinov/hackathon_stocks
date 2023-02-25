//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_EXECUTION_H
#define HACKATHON_STOCKS_EXECUTION_H
#include <string>
#include <iostream>
#include "Order.h"
#include "I_Printable.h"

class Execution: public I_Printable {
friend class Order;
protected:
    std::string executionID;
    int executionQuantity;
    double executionPrice;
    int orderID;
    std::string stockID;
public:
    Execution(const std::string& executionID, int executionQuantity, double executionPrice,std::string stockID, int orderID);
    std::string getStockID() const;
    std::string getOrderID() const;
    void print(std::ostream &os) const override;
    ~Execution() override =default;
};


#endif //HACKATHON_STOCKS_EXECUTION_H
