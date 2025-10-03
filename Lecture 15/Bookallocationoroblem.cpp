#include <iostream>
using namespace std;
bool isPossible(int arr[], int size, int m, int mid)
{
    int count = 1;
    int pages = 0;
    for (int i = 0; i < size; i++)
    {
        if (pages + arr[i] <= mid)
        {
            pages += arr[i];
        }
        else
        {
            count++;
            if ((count > m) || (arr[i] > mid))
            {
                return false;
            }
            pages = arr[i];
        }
    }
    return true;
}
int bookallocation(int arr[], int size, int m)
{
    int l = 0, u = 0, ans = -1;
    for (int i = 0; i < size; i++)
    {
        u += arr[i];
    }
    while (l <= u)
    {
        int mid = l + ((u - l) / 2);
        if (isPossible(arr, size, m, mid))
        {
            ans = mid;
            u = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int books1[4] = {10, 20, 30, 40};
    cout << bookallocation(books1, 4, 2);
}