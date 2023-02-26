#include <iostream>
#include "Order.h"
#include "MarketSimulator.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int lotAmt;
    string compID;
    double price;
    int orderTypeInt;
    MarketSimulator market;

    while(true){
        cin >> lotAmt;
        cin >> compID;
        cin >> price;
        std::cin >> orderTypeInt;
        OrderType orderType = static_cast<OrderType>(orderTypeInt);
        if(orderType==1){

        }
    }
    return 0;
}