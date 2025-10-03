#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// Without DP
int solve(vector<int> &prices, bool buy, int i)
{
    if (i >= prices.size())
    {
        return 0;
    }
    else
    {
        int profit = INT_MIN;
        if (buy)
        { // If buying is allowed
            int brought = -1 * prices[i] + solve(prices, false, i + 1);
            int ignored = solve(prices, true, i + 1);
            profit = max(brought, ignored);
        }
        else
        { // If selling is allowed
            int sold = prices[i] + solve(prices, true, i + 1);
            int ignored = solve(prices, false, i + 1);
            profit = max(sold, ignored);
        }
        return profit;
    }
}
int maxProfit(vector<int> prices)
{
    return solve(prices, true, 0);
}
int main()
{
    cout << maxProfit({7, 1, 5, 3, 6, 4}) << endl;
}