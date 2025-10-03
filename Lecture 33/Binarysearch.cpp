#include <iostream>
using namespace std;
int binary_search(int arr[], int target, int l, int u)
{
    int mid = l + ((u - l) / 2);
    if (l > u)
    {
        return -1;
    }
    else if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binary_search(arr, target, l, mid - 1);
    }
    else
    {
        return binary_search(arr, target, mid + 1, u);
    }
}
int main()
{
    int nums[9] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int nums2[6] = {2, 4, 16, 17, 29, 31};
    int nums3[2] = {6, 23};
    cout << binary_search(nums, 5, 0, 8) << endl;
    cout << binary_search(nums, 16, 0, 8) << endl;
    cout << binary_search(nums2, 10, 0, 5) << endl;
    cout << binary_search(nums2, 31, 0, 5) << endl;
    cout << binary_search(nums3, 23, 0, 1) << endl;
}