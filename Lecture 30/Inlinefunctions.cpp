#include <iostream>
using namespace std;
inline int maximum(int &n, int &m)
{
    return (n > m) ? n : m;
}
int main()
{
    int a = 1, b = 2;
    cout << maximum(a, b) << endl;
}