#include <iostream>
using namespace std;
int Binsearch(int arr[], int size, int key)
{
    int l = 0, u = size - 1;
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
        }
        else
        {
            u = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int even[6] = {1, 2, 4, 6, 7, 8};
    int odd[7] = {1, 2, 4, 4, 7, 8, 9};
    cout << Binsearch(even, 6, 8) << endl
         << Binsearch(odd, 7, 7) << endl
         << Binsearch(even, 6, 45) << endl
         << Binsearch(odd, 6, 5);
}