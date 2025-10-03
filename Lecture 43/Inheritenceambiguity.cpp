#include <iostream>
using namespace std;
class A
{
public:
    void func()
    {
        cout << "I am A" << endl;
    }
};
class B
{
public:
    void func()
    {
        cout << "I am B" << endl;
    }
};
class AB : public A, public B
{
public:
    void func()
    {
        cout << "I am AB" << endl;
    }
};
int main()
{
    AB object;
    // object.func(); Throws an error
    object.A::func();
    object.B::func();
    object.func();
}