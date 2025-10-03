#include <iostream>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;
    }
    cout << ans;
}