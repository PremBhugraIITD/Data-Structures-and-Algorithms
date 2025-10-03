#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 0)
    {
        cout << b;
    }
    else if (b == 0)
    {
        cout << a;
    }
    else
    {
        while (a != b)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
        cout << a;
    }
}