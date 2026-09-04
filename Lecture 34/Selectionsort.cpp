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
void selection_sort(int arr[], int size)
{
    if (size == 1)
    {
        return;
    }
    else
    {
        // This loop sorts the minimum element, i.e., brings the minimum element to the beginning of the array
        int minindex = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < arr[minindex])
            {
                minindex = i;
            }
        }
        swap(arr[0], arr[minindex]);
        selection_sort(arr + 1, size - 1);
    }
}
int main()
{
    int nums[5] = {2, 1, 5, 3, 4};
    int nums2[7] = {2, 13, 2, -1, 35, 22, 1};
    selection_sort(nums, 5);
    printArray(nums, 5);
    selection_sort(nums2, 7);
    printArray(nums2, 7);
}