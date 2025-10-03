#include <iostream>
using namespace std;
int First(int arr[], int size, int key)
{
    int l = 0, u = size - 1, ans = -1;
    while (l <= u)
    {
        int mid = l + ((u - l) / 2);
        if (arr[mid] == key)
        {
            ans = mid;
            u = mid - 1;
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
    return ans;
}
int Last(int arr[], int size, int key)
{
    int l = 0, u = size - 1, ans = -1;
    while (l <= u)
    {
        int mid = l + ((u - l) / 2);
        if (arr[mid] == key)
        {
            ans = mid;
            l = mid + 1;
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
    return ans;
}

int main()
{
    int numbers1[6] = {0, 5, 5, 6, 6, 6};
    cout << First(numbers1, 6, 3) << endl;
    cout << Last(numbers1, 6, 3) << endl;
    int numbers2[8] = {0, 0, 1, 1, 2, 2, 2, 2};
    cout << First(numbers2, 8, 2) << endl;
    cout << Last(numbers2, 8, 2) << endl;
}