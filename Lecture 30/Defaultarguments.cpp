#include <iostream>
using namespace std;
void print(int arr[], int size, int start = 0)
{ // start is a Default Argument
    for (int i = start; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    print(arr, 5);
    cout << endl;
    print(arr, 5, 3);
}