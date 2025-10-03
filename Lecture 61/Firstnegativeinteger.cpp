#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> Firstnegative(vector<int> nums, int k)
{
    vector<int> ans;
    deque<int> d;
    // d.front() will contain the index of the first negative element in the k sized window
    for (int i = 0; i < k; i++)
    {
        if (nums[i] < 0)
        {
            d.push_back(i);
        }
    }
    if (!d.empty())
    {
        ans.push_back(nums[d.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (i - d.front() >= k)
        {
            d.pop_front();
        }
        if (nums[i] < 0)
        {
            d.push_back(i);
        }
        if (!d.empty())
        {
            ans.push_back(nums[d.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(12);
    nums.push_back(-1);
    nums.push_back(-7);
    nums.push_back(8);
    nums.push_back(-15);
    nums.push_back(30);
    nums.push_back(16);
    nums.push_back(28);
    vector<int> ans = Firstnegative(nums, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}