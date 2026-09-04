#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void Insertionsort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (temp < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
    printArray(arr, size);
}
int main()
{
    int numbers1[6] = {6, 5, 4, 3, 2, 1};
    int numbers2[8] = {12, 14, 2, 35, 23, 9, 2, 0};
    int numbers3[7] = {10, 1, 7, 4, 8, 2, 11};
    Insertionsort(numbers1, 6);
    Insertionsort(numbers2, 8);
    Insertionsort(numbers3, 7);
}