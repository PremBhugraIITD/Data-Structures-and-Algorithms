#include <iostream>
using namespace std;
int pivot1(int arr[], int size)
{
    int l = 0, u = size - 1, ans;
    while (l <= u)
    {
        long long int mid = l + ((u - l) / 2);
        if (arr[mid] >= arr[0])
        {
            l = mid + 1;
        }
        else
        {
            u = mid - 1;
        }
        ans = mid;
    }
    return ans;
}
int Binsearch(int arr[], int size, int key, int l, int u)
{
    while (l <= u)
    {
        int mid = l + ((u - l) / 2);
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
            continue;
        }
        else
        {
            u = mid - 1;
            continue;
        }
    }
    return -1;
}
int search(int arr[], int size, int key)
{
    if ((key >= arr[0]) && (key < arr[pivot1(arr, size)]))
    {
        cout << Binsearch(arr, size, key, 0, pivot1(arr, size) - 1);
    }
    else
    {
        cout << Binsearch(arr, size, key, pivot1(arr, size), size - 1);
    }
}
int main()
{
    int numbers[5] = {12, 15, 18, 2, 4};
    search(numbers, 5, 2);
    cout << endl;
    search(numbers, 5, 17);
}