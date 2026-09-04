#include <iostream>
using namespace std;
class A
{
public:
    int a;
    int b;
    int add()
    {
        return a + b;
    }
    void operator+(A &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "Called for object of a = " << this->a << endl;
        cout << "Output: " << value2 + value1 << endl;
    }
    int operator-(A &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "Called for object of a = " << this->a << endl;
        cout << "Output: ";
        return value2 - value1;
    }
};
int main()
{
    A object;
    object.a = 5;
    object.b = 10;
    cout << object.add() << endl;
    A object1, object2;
    object1.a = 23;
    object2.a = 27;
    object1 + object2;
    cout << object1 - object2 << endl;
}