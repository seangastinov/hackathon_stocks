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

    marketSimulator.addOrder("AAPL", 100, 80, OrderType::SELL, Sean);
    cout << Sean << endl;
    marketSimulator.addOrder("AAPL", 5, 90, OrderType::SELL, Joe);
    cout << Joe << endl;
    marketSimulator.addOrder("AAPL", 30, 100, OrderType::SELL, Moe);
    cout << Moe << endl;
    marketSimulator.addOrder("AAPL",10 , 40, OrderType::SELL, Larry);
    cout << Larry << endl;

    marketSimulator.addOrder("AAPL", 110, 80, OrderType::BUY, Fio);
    cout << Fio;
    cout << Sean;
    cout << Joe;
    cout << Moe;

    cout << Larry;

    return 0;
}