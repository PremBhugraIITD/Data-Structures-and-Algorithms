#include <iostream>
using namespace std;
int Peak(int arr[], int size)
{
    int l = 0, u = size - 1, mid = l + ((u - l) / 2);
    while (l < u)
    {
        if (arr[mid] < arr[mid + 1])
        {
            l = mid + 1;
        }
        else
        {
            u = mid;
        }
        mid = l + ((u - l) / 2);
    }
    return mid;
}
int main()
{
    int numbers1[4] = {0, 10, 5, 2};
    int numbers2[9] = {1, 4, 5, 8, 16, 23, 11, 3, 2};
    int numbers3[10] = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    cout << Peak(numbers1, 4) << endl
         << Peak(numbers2, 9) << endl
         << Peak(numbers3, 10);
}