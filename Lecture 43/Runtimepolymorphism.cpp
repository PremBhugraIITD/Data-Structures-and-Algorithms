#include <iostream>
using namespace std;
class A
{
public:
    void func()
    {
        cout << "Called for A" << endl;
    }
};
class B : public A
{
public:
    void func()
    {
        cout << "Called for B" << endl;
    }
};
int main()
{
    B object;
    object.func();
}