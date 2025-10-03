#include <iostream>
using namespace std;
void update1(int **p)
{
    p = p + 1;
}
void update2(int **p)
{
    *p = *p + 1;
}
void update3(int **p)
{
    **p = **p + 1;
}
int main()
{
    int i = 5;
    int *ptr = &i;
    int **ptr2 = &ptr;
    cout << ptr << " " << &ptr << " " << ptr2 << " " << &ptr2 << " " << *ptr2 << " " << **ptr2 << endl;
    update1(ptr2);
    cout << ptr << " " << &ptr << " " << ptr2 << " " << &ptr2 << " " << *ptr2 << " " << **ptr2 << endl;
    update2(ptr2);
    cout << ptr << " " << &ptr << " " << ptr2 << " " << &ptr2 << " " << *ptr2 << " " << **ptr2 << endl;
    update3(ptr2);
    cout << ptr << " " << &ptr << " " << ptr2 << " " << &ptr2 << " " << *ptr2 << " " << **ptr2 << endl;
    int first = 10;
    int *ptr3 = 0;
    ptr3 = &first;
    cout << *ptr3 << endl;
    int arr[6] = {11, 21, 31};
    int *ptr4 = arr;
    cout << ptr4[2] << endl;
    char arr2[] = "abcde";
    char *ptr5 = &arr2[0];
    cout << ptr5 << endl;
    char arr3[] = "abcde";
    char *ptr6 = &arr3[0];
    ptr6++;
    cout << ptr6 << endl;
}