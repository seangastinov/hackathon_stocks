//
// Created by Sean Gastinov on 26/02/23.
//

#ifndef HACKATHON_STOCKS_COMPANY_H
#define HACKATHON_STOCKS_COMPANY_H
#include <queue>
#include <unordered_map>
#include <string>
#include "pricelotbuy.h"
#include "pricelotsell.h"

using namespace std;
struct company{
    priority_queue<pricelotbuy> buy;
    priority_queue<pricelotsell> sell;
public:
    priority_queue<pricelotbuy> getQueueBuy() const {
        return buy;
    }
    priority_queue<pricelotsell> getQueueSell() const{
        return sell;
    }
};

void build(std::string name, unordered_map<std::string, company> &companies){
    company temp;
    companies[name]=temp;
}



#endif //HACKATHON_STOCKS_COMPANY_H
