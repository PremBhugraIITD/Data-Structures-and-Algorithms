#include <iostream>
#include <vector>
using namespace std;
// Without DP
int solve(vector<int> weight, vector<int> value, int i, int maxWeight)
{
    if (i == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    int include = 0, exclude = 0;
    if (weight[i] <= maxWeight)
    {
        include = value[i] + solve(weight, value, i - 1, maxWeight - weight[i]);
    }
    exclude = solve(weight, value, i - 1, maxWeight);
    return max(include, exclude);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n - 1, maxWeight);
}
int main()
{
    cout << knapsack({1, 2, 4, 5}, {5, 4, 8, 6}, 4, 5) << endl;
}