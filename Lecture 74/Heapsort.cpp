#include <iostream>
using namespace std;
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;
    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}
void max_heap_sort(int arr[], int size)
{
    while (size > 1)
    {
        swap(arr[1], arr[size--]); // The first element was the maximum so it should is sent to the end
        heapify(arr, size, 1);     // then the heapify function converts the the subarray excluding the last element into a valid heap
    }
}
// TC=O(nlog(n))
int main()
{
    int arr[6] = {-1, 70, 60, 55, 45, 50};
    max_heap_sort(arr, 5);
    for (int i = 1; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}