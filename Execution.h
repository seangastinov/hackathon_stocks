//
// Created by Sean Gastinov on 25/02/23.
//

#ifndef HACKATHON_STOCKS_EXECUTION_H
#define HACKATHON_STOCKS_EXECUTION_H
#include <string>
#include <iostream>
#include "Order.h"
#include "BuyOrder.h"
#include "SellOrder.h"
#include "I_Printable.h"

class Execution: public I_Printable {
friend class BuyOrder;
protected:
    int executionID{};
    int executionQuantity;
    std::string stockID;
    double profit;
public:
    Execution(const BuyOrder& buyOrder, const SellOrder& sellOrder, int executionQuantity, int executionID);
    std::string getStockID() const;
    int getexecutionID() const;
    void print(std::ostream &os) const override;
    ~Execution() override =default;
};


#endif //HACKATHON_STOCKS_EXECUTION_H
