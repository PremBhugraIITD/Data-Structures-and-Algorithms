#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sum_of_arrays(int arr1[], int size1, int arr2[], int size2)
{
    vector<int> result;
    int i = size1 - 1, j = size2 - 1;
    int carry = 0;
    while ((i >= 0) && (j >= 0))
    {
        int digit_sum = carry + arr1[i--] + arr2[j--];
        if (digit_sum <= 9)
        {
            result.push_back(digit_sum);
            carry = 0;
        }
        else if (digit_sum == 20)
        {
            result.push_back(0);
            carry = 2;
        }
        else
        {
            result.push_back(digit_sum % 10);
            carry = 1;
        }
    }
    while (i >= 0)
    {
        int digit_sum = carry + arr1[i--];
        if (digit_sum != 10)
        {
            result.push_back(digit_sum);
            carry = 0;
        }
        else
        {
            result.push_back(0);
            carry = 1;
        }
    }
    while (j >= 0)
    {
        int digit_sum = carry + arr2[j--];
        if (digit_sum != 10)
        {
            result.push_back(digit_sum);
            carry = 0;
        }
        else
        {
            result.push_back(0);
            carry = 1;
        }
    }
    if (carry == 1)
    {
        result.push_back(1);
    }
    else if (carry == 2)
    {
        result.push_back(2);
    }
    reverse(result.begin(), result.end());
    for (auto n : result)
    {
        cout << n << " ";
    }
    cout << endl;
}
int main()
{
    int nums1[3] = {1, 2, 3}, nums2[2] = {9, 9};
    sum_of_arrays(nums1, 3, nums2, 2);
}