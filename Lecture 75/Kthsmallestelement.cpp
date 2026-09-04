#include <iostream>
#include <queue>
using namespace std;
#include <iostream>
using namespace std;
int kthsmallest(int arr[], int size, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < size; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // The first k smallest elements are now present in the heap
    return pq.top();
}
int main()
{
    int nums[6] = {7, 10, 4, 3, 20, 15};
    cout << kthsmallest(nums, 6, 3) << endl;
}