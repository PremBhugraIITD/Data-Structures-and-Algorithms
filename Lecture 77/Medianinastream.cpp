#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{
    switch (signum(maxi.size(), mini.size()))
    {
    case 0:
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }
        break;
    case 1:
        if (element > median)
        {
            mini.push(element);
            median = (maxi.top() + mini.top()) / 2;
        }
        else
        {
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(element);
            median = (maxi.top() + mini.top()) / 2;
        }
        break;
    case -1:
        if (element < median)
        {
            maxi.push(element);
            median = (maxi.top() + mini.top()) / 2;
        }
        else
        {
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median = (maxi.top() + mini.top()) / 2;
        }
        break;
    }
}
vector<int> Median(vector<int> arr)
{
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}
// TC = O(nlog(n))
int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(6);
    nums.push_back(8);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    vector<int> ans = Median(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}