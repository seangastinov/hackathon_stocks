#include <iostream>
#include "Order.h"
#include "MarketSimulator.h"
#include "Account.h"
using namespace std;

int main() {
    MarketSimulator marketSimulator;
    Account Sean(1, "Sean");
    Account Joe(2, "Joe");
    Account Moe(3, "Moe");
    Account Larry(4, "Larry");
    Account Fio(5, "Fio");

    marketSimulator.addOrder("AAPL", 100, 80, OrderType::BUY, Sean);
    //marketSimulator.addOrder("AAPL", 5, 90, OrderType::BUY, Joe);
    marketSimulator.addOrder("AAPL", 30, 100, OrderType::BUY, Moe);

    //marketSimulator.addOrder("AAPL",5 , 85, OrderType::BUY, Larry);

    marketSimulator.addOrder("AAPL", 110, 80, OrderType::SELL, Fio);
    cout << Fio;
    Fio.updateOrder();
    cout << Sean;
    Sean.updateOrder();
    return 0;
}