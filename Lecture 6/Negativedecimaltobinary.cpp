#include <iostream>

#include <math.h>

using namespace std;

int main(void)
{

    long long int n;

    cin >> n;

    long long int i = 0, ans = 0;
    n = pow(2, 16) + n;

    cout << n << endl;

    while (n)
    {

        int lastBit = n & 1;

        ans = (pow(10, i) * lastBit) + ans;

        n = n >> 1;

        i++;

        cout << ans << endl;
    }

    cout << ans << endl; // It will not give the correct answer here but on an online IDE.

    return 0;
}