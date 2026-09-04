#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubble_sort(int arr[], int size)
{
    if (size == 1)
    {
        return;
    }
    else
    {
        // This loop sorts the maximum element, i.e., brings the maximum element to the end of the array
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        bubble_sort(arr, size - 1);
    }
}
int main()
{
    int nums[5] = {2, 1, 5, 3, 4};
    int nums2[7] = {2, 13, 2, -1, 35, 22, 1};
    bubble_sort(nums, 5);
    printArray(nums, 5);
    bubble_sort(nums2, 7);
    printArray(nums2, 7);
}