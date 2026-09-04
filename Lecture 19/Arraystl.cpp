#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 4> a = {2, 4, 1, 8};
    cout << a.size() << endl
         << a.at(2) << endl
         << a.empty() << endl
         << a.front() << endl
         << a.back() << endl;
}