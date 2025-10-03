#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1, 10, 100, 1000, 10000};
    cout << "Address of arr[0] is " << &arr[0] << endl;
    cout << "Address of arr[0] is " << arr << endl;
    cout << "Value of arr[0] is " << *arr << endl;
    cout << "Value of arr[0] + 1 is " << *arr + 1 << endl;
    cout << "Value of arr[0] + 1 is " << (*arr) + 1 << endl;
    cout << "Value of arr[0] + 1 is " << *(arr) + 1 << endl;
    cout << "Value of arr[1] is " << *(arr + 1) << endl;
    cout << "Value of arr[1] is " << arr[1] << endl;
    cout << "Value of arr[1] is " << 1 [arr] << endl;
    double temp[10];
    double *ptr = &temp[0];
    cout << sizeof(temp) << " " << sizeof(ptr) << " " << sizeof(*ptr) << " " << sizeof(&ptr) << endl;
    cout << "Address of temp[0] is " << &temp[0] << endl;
    cout << "Address of ptr is " << &ptr << endl;
    cout << ptr << endl;
    // temp=temp+1; Throws and error because we are trying to change the symbol table
    ptr = ptr + 1;
    cout << "Address of temp[1] is " << ptr << endl;
    cout << "Address of temp[1] is " << &temp[1] << endl;
}