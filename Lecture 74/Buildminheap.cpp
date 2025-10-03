#include <iostream>
using namespace std;
void heapify(int arr[], int size, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;
    if (left <= size && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right <= size && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, size, smallest);
    }
}
int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 5;
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}