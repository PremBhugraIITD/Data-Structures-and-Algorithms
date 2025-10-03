#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void Selectionsort(int arr[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        int minindex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minindex] > arr[j])
            {
                minindex = j;
            }
        }
        swap(arr[minindex], arr[i]);
    }
}
int main()
{
    int numbers1[5] = {64, 25, 12, 22, 11}, numbers2[6] = {6, 2, 8, 4, 10, 9}, numbers3[8] = {45, 5, 5, 79, 84, 79, 12, 7};
    Selectionsort(numbers1, 5);
    printArray(numbers1, 5);
    Selectionsort(numbers2, 6);
    printArray(numbers2, 6);
    Selectionsort(numbers3, 8);
    printArray(numbers3, 8);
}