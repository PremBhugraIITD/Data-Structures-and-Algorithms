#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// Without DP
int solve(vector<int> num, int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (auto i : num)
    {
        int ans = solve(num, x - i);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int ans = solve(num, x);
    if (ans == INT_MAX)
    {
        ans = -1;
    }
    return ans;
}
// Top Down Approach
int solve2(vector<int> num, int x, vector<int> &dp)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x < 0)
    {
        return INT_MAX;
    }
    if (dp[x] == -1)
    {
        int mini = INT_MAX;
        for (auto i : num)
        {
            int ans = solve2(num, x - i, dp);
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }
        dp[x] = mini;
    }
    return dp[x];
}
int minimumElements2(vector<int> &num, int x)
{
    vector<int> dp(x + 1, -1);
    int ans = solve2(num, x, dp);
    if (ans == INT_MAX)
    {
        ans = -1;
    }
    return ans;
}
int main()
{
    vector<int> elements = {1, 2, 3};
    cout << minimumElements(elements, 7) << "   " << minimumElements2(elements, 7);
}