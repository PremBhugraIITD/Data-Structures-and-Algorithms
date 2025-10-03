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
void insertion_sort(int arr[], int size)
{
    if (size == 1)
    {
        return;
    }
    else
    {
        insertion_sort(arr, size - 1);
        // Value of i goes from 1 to size-1 after all the recursive iterations (just like in the case of loops)
        int i = size - 1;
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int nums[5] = {2, 1, 5, 3, 4};
    int nums2[7] = {2, 13, 2, -1, 35, 22, 1};
    insertion_sort(nums, 5);
    printArray(nums, 5);
    insertion_sort(nums2, 7);
    printArray(nums2, 7);
}