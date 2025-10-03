#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// Without DP
int solve(int i, int operation, vector<int> &prices, int k)
{
    if (i >= prices.size())
    {
        return 0;
    }
    else if (operation == 2 * k)
    { // If
        return 0;
    }
    else
    {
        int profit = INT_MIN;
        if (operation % 2 == 0)
        { // If operation number is even then buying the stock is allowed
            int bought = -1 * prices[i] + solve(i + 1, operation + 1, prices, k);
            int ignored = solve(i + 1, operation, prices, k);
            profit = max(bought, ignored);
        }
        else
        { // If operation number is odd then selling the stock is allowed
            int sold = prices[i] + solve(i + 1, operation + 1, prices, k);
            int ignored = solve(i + 1, operation, prices, k);
            profit = max(sold, ignored);
        }
        return profit;
    }
}
int maxProfit(int k, vector<int> prices)
{
    return solve(0, 0, prices, k);
}
int main()
{
    cout << maxProfit(2, {3, 2, 6, 5, 0, 3}) << endl;
}