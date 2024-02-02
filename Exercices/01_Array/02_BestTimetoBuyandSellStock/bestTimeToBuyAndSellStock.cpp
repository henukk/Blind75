#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int minPrice = prices[0];
    int size = prices.size();
    for (int i = 1; i < size; ++i)
    {
        profit = max(profit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return profit;
}