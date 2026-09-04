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
void merge(int arr[], int l, int u)
{ // Merge function merges two sorted arrays and the resulting array is sorted itself
    int mid = l + ((u - l) / 2);
    int size1 = mid + 1 - l, size2 = u - mid;
    int *first = new int[size1], *second = new int[size2];
    int j = l;
    for (int i = 0; i < size1; i++)
    {
        first[i] = arr[j++];
    }
    j = mid + 1;
    for (int i = 0; i < size2; i++)
    {
        second[i] = arr[j++];
    }
    int a = 0, b = 0;
    int x = l;
    while (a < size1 && b < size2)
    {
        if (first[a] > second[b])
        {
            arr[x++] = second[b++];
        }
        else
        {
            arr[x++] = first[a++];
        }
    }
    while (a < size1)
    {
        arr[x++] = first[a++];
    }
    while (b < size2)
    {
        arr[x++] = second[b++];
    }
    delete[] first;
    delete[] second;
}
void merge_sort(int arr[], int l, int u)
{
    {
        if (l >= u)
        {
            return;
        }
        else
        {
            int mid = l + ((u - l) / 2);
            merge_sort(arr, l, mid);     // Sorts the left halfs
            merge_sort(arr, mid + 1, u); // Sorts the right halfs
            merge(arr, l, u);            // Merges the two sorted halfs
        }
    }
}
int main()
{
    int nums[5] = {2, 1, 5, 3, 4};
    int nums2[7] = {2, 13, 2, -1, 35, 22, 1};
    merge_sort(nums, 0, 4);
    printArray(nums, 5);
    merge_sort(nums2, 0, 6);
    printArray(nums2, 7);
}