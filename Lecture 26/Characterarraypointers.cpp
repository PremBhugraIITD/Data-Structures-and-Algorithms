#include <iostream>
using namespace std;
int main()
{
    char name[5] = "prem";
    cout << "Content of name is " << name << endl;
    char *ptr = &name[0];
    cout << "Content of name is " << ptr << endl;
    cout << "name[0] is " << *ptr << endl;
    cout << "name[0] is " << *name << endl;
    char c = 'a';
    char *ptr2 = &c;
    cout << ptr2 << endl;
}