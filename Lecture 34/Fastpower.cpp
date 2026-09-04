#include <iostream>
using namespace std;
int fast_power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return m;
    }
    int x = fast_power(m, n / 2);
    if (n % 2 == 0)
    {
        return x * x;
    }
    else
    {
        return x * x * m;
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << fast_power(a, b) << endl;
}