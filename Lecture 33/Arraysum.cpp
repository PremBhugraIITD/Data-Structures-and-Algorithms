#include <iostream>
using namespace std;
int arr_sum(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    else
    {
        return (arr[0] + arr_sum(arr + 1, size - 1));
    }
}
int main()
{
    int nums[6] = {2, 1, 6, 23, 4, 1};
    int nums2[9] = {91, 2, 3, 4, 23, 12, 987, 23, 66};
    cout << arr_sum(nums, 6) << endl;
    cout << arr_sum(nums2, 9) << endl;
}