# hackathon_stocks
Implement stock order book with account by using OOP

Algorithm: 
1. Prioritize highest price of buy order and lowest price of sell order.
2. If the price is the same, then order that has been created first will be executed first (first in first out)
3. Executions will be created if and only if:
 - buyer price >= seller price
