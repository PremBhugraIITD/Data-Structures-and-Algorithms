#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;
    if (left < arr.size() && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < arr.size() && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest);
    }
}
vector<int> merge_heaps(int arr1[], int size1, int arr2[], int size2)
{
    vector<int> ans;
    for (int i = 1; i <= size1; i++)
    {
        ans.push_back(arr1[i]);
    }
    for (int i = 1; i <= size2; i++)
    {
        ans.push_back(arr2[i]);
    }
    for (int i = (size1 + size2) / 2; i >= 0; i--)
    {
        heapify(ans, i);
    }
    return ans;
}
int main()
{
    int nums1[5] = {-1, 10, 5, 6, 2};
    int nums2[4] = {-1, 12, 7, 9};
    vector<int> ans = merge_heaps(nums1, 4, nums2, 3);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}