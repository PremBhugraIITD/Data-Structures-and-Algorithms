#include <iostream>
using namespace std;
class MaxHeap
{
public:
    int *arr;
    int size;
    MaxHeap(int n)
    {
        arr = new int[n];
        this->size = 0;
    }
    void insert(int data)
    {
        size++;
        int index = size;
        arr[index] = data;
        while (index > 1)
        {
            int parent_index = index / 2;
            if (arr[index] > arr[parent_index])
            {
                swap(arr[index], arr[parent_index]);
                index = parent_index;
            }
            else
            {
                return;
            }
        }
    }
    // TC=O(log(n))
    void deleteElement()
    { // Deletes the root
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[size--];
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex <= size && arr[i] < arr[leftindex] && arr[leftindex] > arr[rightindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex <= size && arr[i] < arr[rightindex] && arr[leftindex] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
        // TC=O(log(n))
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
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
// TC=O(log(n))
int main()
{
    MaxHeap mh(100);
    mh.insert(60);
    mh.insert(50);
    mh.insert(55);
    mh.insert(30);
    mh.insert(20);
    mh.insert(40);
    mh.print();
    mh.deleteElement();
    mh.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 5;
    for (int i = size / 2; i > 0; i--)
    { // Heapifying the elements from size/2 to 1 because the rest of the elements are present at leaf node positions
        heapify(arr, size, i);
    }
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
}