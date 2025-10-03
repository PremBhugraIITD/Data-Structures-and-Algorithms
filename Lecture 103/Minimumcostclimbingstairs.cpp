#include <iostream>
#include <vector>
using namespace std;
// Without DP
int minCost(int n, vector<int> cost)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return cost[0];
    }
    else if (n == 2)
    {
        return min(cost[0], cost[1]);
    }
    else if (n == 3)
    {
        return min(cost[1], cost[0] + cost[2]);
    }
    else
    {
        return min(minCost(n - 1, cost) + cost[n - 1], minCost(n - 2, cost) + cost[n - 2]);
    }
}
int main()
{
    cout << minCost(3, {10, 15, 20}) << "   " << minCost(10, {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}) << endl;
}