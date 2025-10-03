#include <iostream>
#include <queue>
using namespace std;
int kth_largest_sum(int arr[], int size, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap which should finally contain the maximum k elements
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else if (pq.top() < sum) // If pq.top() < sum then pq.top() is not among the maximum k elements so pop it and push sum
            {
                pq.pop();
                pq.push(sum);
            }
        }
    }
    return pq.top(); // The top element is now the minimum among the maximum k elements
}
// TC=O(n^2log(k))
// SC=O(k)
int main()
{
    int arr[5] = {1, -2, 3, -4, 5};
    cout << kth_largest_sum(arr, 5, 2);
}