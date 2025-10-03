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
int partition(int arr[], int l, int u)
{ /*Brings the pivot to the correct place, puts the elements smaller than
pivot to its left and those greater than pivot to its right and returns the index of pivot*/
    int count = 0;
    int pivot = arr[l];
    for (int i = l + 1; i <= u; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = l + count;
    swap(arr[l], arr[pivotIndex]);
    int a = l, b = u;
    while (a < pivotIndex && b > pivotIndex)
    {
        while (arr[a] <= pivot)
        {
            a++;
        }
        while (arr[b] > pivot)
        {
            b--;
        }
        if (a < pivotIndex && b > pivotIndex)
        {
            swap(arr[a++], arr[b--]);
        }
    }
    return pivotIndex;
}
void quick_sort(int arr[], int l, int u)
{
    if (l >= u)
    {
        return;
    }
    else
    {
        int p = partition(arr, l, u);
        quick_sort(arr, l, p - 1); // Sorts the part to the left of pivot
        quick_sort(arr, p + 1, u); // Sorts the part to the rigth of pivot
    }
}
int main()
{
    int nums[5] = {2, 1, 5, 3, 4};
    int nums2[7] = {2, 13, 2, -1, 35, 22, 1};
    quick_sort(nums, 0, 4);
    printArray(nums, 5);
    quick_sort(nums2, 0, 6);
    printArray(nums2, 7);
}