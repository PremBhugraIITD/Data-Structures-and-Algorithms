#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(2);
    v.push_back(5);
    v.push_back(23);
    v.push_back(7);
    cout << binary_search(v.begin(), v.end() + 1, 23) << endl
         << binary_search(v.begin(), v.end() + 1, 3) << endl;
    cout << max(7, 1) << endl
         << min(7, 3) << endl;
    int a = 8, b = 0;
    swap(a, b);
    cout << a << endl
         << b << endl;
    string name = "Prem";
    cout << name << endl;
    reverse(name.begin(), name.end());
    cout << name << endl;
    rotate(v.begin(), v.begin() + 1, v.end());
    for (int i : v)
    {
        cout << i << endl;
    }
    sort(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << endl;
    }
}