#include <iostream>
using namespace std;
int main()
{
    int num = 5;
    cout << "Address of num is " << &num << endl;
    int *ptr = &num;
    cout << "Value of num is " << *ptr << endl;
    cout << "Address of num is " << ptr << endl;
    cout << "Size of pointer is " << sizeof(ptr) << endl;
    cout << "Size of num is " << sizeof(*ptr) << endl;
    double nums = 3.35;
    cout << "Address of nums is " << &nums << endl;
    double *ptr2 = &nums;
    cout << "Value of nums is " << *ptr2 << endl;
    cout << "Address of nums is " << ptr2 << endl;
    cout << "Size of pointer is " << sizeof(ptr2) << endl;
    cout << "Size of nums is " << sizeof(*ptr2) << endl;
    int i = 3;
    int *ptr3 = &i;
    int *ptr4 = 0;
    ptr4 = &i;
    cout << ptr3 << " " << *ptr3 << " " << ptr4 << " " << *ptr4 << endl;
    int a = 5;
    int b = a;
    b++;
    cout << b << " " << a << endl;
    int *ptr5 = &a;
    (*ptr5)++;
    cout << *ptr5 << " " << a << endl;
    // Copying a pointer into another
    char c = 'p';
    char *ptr6 = &c;
    char *ptr7 = ptr6;
    cout << ptr6 << " " << ptr7 << endl;
    cout << *ptr6 << " " << *ptr7 << endl;
    cout << sizeof(ptr6) << " " << sizeof(ptr7) << endl;
    int z = 7;
    int *ptr8 = &z;
    cout << ptr8 << endl;
    (*ptr8)++;
    cout << ptr8 << endl;
    ptr8++;
    cout << ptr8 << endl;
    int *p = 0;
    cout << *p << " " << p << endl;
    cout << "This line won't be printed because compilation stops at the point we call *p" << endl;
}