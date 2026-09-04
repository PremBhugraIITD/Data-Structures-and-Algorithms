#include <iostream>
using namespace std;
class A
{
public:
    void hello()
    {
        cout << "Hello Prem Bhugra" << endl;
    }
    void hello(string name)
    {
        cout << "Hello " << name << endl;
    }
};
int main()
{
    A object;
    object.hello();
    object.hello("Gaurav Verma");
}