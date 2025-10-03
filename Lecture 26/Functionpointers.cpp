#include <iostream>
using namespace std;
void print(int *p)
{
    cout << *p << " " << p << endl;
}
void updateaddress(int *p)
{
    p = p + 1;
    cout << *p << " " << p << endl;
}
void updatevalue(int *p)
{
    *p = *p + 1;
    cout << *p << " " << p << endl;
}
int printsize(int arr[], int size)
{                                                       // We can also write int *arr instead of int arr[]
    cout << "Size of array is " << sizeof(arr) << endl; /*This does not give the size of the array as 5 x 4 = 20 but
          instead gives the size of the pointer 'arr' = 4 because the array name is always passed as a pointer whenever
          it is passed as a function argument. The terminal even throws a warning about this when we use 'int arr[]'
          as the argument */
}
int sumofarray(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int value = 5;
    int *ptr = &value;
    print(ptr);
    updateaddress(ptr);
    print(ptr);
    updatevalue(ptr);
    print(ptr);
    int arr[5] = {1, 2, 3, 4, 5};
    printsize(arr, 5);
    cout << sumofarray(arr, 5) << endl;
    cout << sumofarray(arr + 3, 2) << endl;
}