#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void Sortit(int arr[], int size)
{
    int count0 = 0, count1 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        if (arr[i] == 1)
        {
            count1++;
        }
    }
    for (int j = 0; j < count0; j++)
    {
        arr[j] = 0;
    }
    for (int k = count0; k < (count0 + count1); k++)
    {
        arr[k] = 1;
    }
    for (int l = (count0 + count1); l < size; l++)
    {
        arr[l] = 2;
    }

    printArray(arr, size);
}
int main()
{
    int numbers[13] = {
        0,
        1,
        1, 2,
        0,
        0,
        1, 2, 2,
        1,
        0,
        0, 2};
    Sortit(numbers, 13);
}