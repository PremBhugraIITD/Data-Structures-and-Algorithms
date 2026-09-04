#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// Without DP
int solve(vector<int> num, int i)
{ // i denotes the last index
    if (i < 0)
    {
        return 0;
    }
    else if (i == 0)
    {
        return num[0];
    }
    int ans1 = solve(num, i - 2) + num[i]; // Inlcusion
    int ans2 = solve(num, i - 1);          // Exclusion
    return max(ans1, ans2);
}
int maximum_sum(vector<int> num)
{
    int n = num.size();
    return solve(num, n - 1);
}
int main()
{
    vector<int> num = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    cout << maximum_sum(num) << endl;
}