#include <iostream>
#include <vector>
using namespace std;
// Without DP
int solve(vector<int> num, int i, bool &visited)
{ // i denotes the last index
    if (i < 0)
    {
        return 0;
    }
    else if (i == 0)
    {
        if (visited == false)
        {
            return num[0];
        }
        else
        {
            return 0;
        }
    }
    if (i == num.size() - 1)
    {
        visited = true;
    }
    int ans1 = solve(num, i - 2, visited) + num[i]; // Inlcusion
    if (i == num.size() - 1)
    {
        visited = false;
    }
    int ans2 = solve(num, i - 1, visited); // Exclusion
    return max(ans1, ans2);
}
int houseRobber(vector<int> valueInHouse)
{
    int n = valueInHouse.size();
    bool visited = false; // Tells whether last element was included or not
    return solve(valueInHouse, n - 1, visited);
}
int main()
{
    cout << houseRobber({1, 3, 2, 1}) << "    " << houseRobber({2, 3, 2}) << endl;
}