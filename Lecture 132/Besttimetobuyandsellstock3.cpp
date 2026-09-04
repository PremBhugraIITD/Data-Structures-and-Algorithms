#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// Without DP
int solve(vector<int> &prices, bool buy, int i, int transaction)
{
    if (transaction == 2)
    {
        return 0;
    }
    if (i >= prices.size())
    {
        return 0;
    }
    else
    {
        int profit = INT_MIN;
        if (buy)
        { // If buying is allowed
            int brought = -1 * prices[i] + solve(prices, false, i + 1, transaction);
            int ignored = solve(prices, true, i + 1, transaction);
            profit = max(brought, ignored);
        }
        else
        { // If selling is allowed
            int sold = prices[i] + solve(prices, true, i + 1, transaction + 1);
            int ignored = solve(prices, false, i + 1, transaction);
            profit = max(sold, ignored);
        }
        return profit;
    }
}
int maxProfit(vector<int> prices)
{
    return solve(prices, true, 0, 0);
}
int main()
{
    cout << maxProfit({3, 3, 5, 0, 0, 3, 1, 4}) << endl;
}