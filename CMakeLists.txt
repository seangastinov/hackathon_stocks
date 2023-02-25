cmake_minimum_required(VERSION 3.23)
project(hackathon_stocks)

set(CMAKE_CXX_STANDARD 14)

add_executable(hackathon_stocks main.cpp Order.cpp Order.h I_Printable.cpp I_Printable.h BuyOrder.cpp BuyOrder.h SellOrder.cpp SellOrder.h Execution.cpp Execution.h MarketSimulator.cpp MarketSimulator.h pricelotbuy.h pricelotsell.h Account.cpp Account.h)
