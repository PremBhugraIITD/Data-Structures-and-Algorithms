#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int sum_max_min(vector<int> arr, int k)
{
    deque<int> maxi(k); // Front element of maxi is the greatest element in the k sized window
    deque<int> mini(k); // Front element of mini is the smallest element in the k sized window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int sum = 0;
    for (int i = k; i < arr.size(); i++)
    {
        sum += arr[maxi.front()] + arr[mini.front()];
        if (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        if (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    // For calculating the sum for the last window
    sum += arr[maxi.front()] + arr[mini.front()];
    return sum;
}
// TC=O(n)
// SC=O(n)
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(-1);
    nums.push_back(7);
    nums.push_back(-3);
    nums.push_back(-1);
    nums.push_back(-2);
    cout << sum_max_min(nums, 4) << endl;
}