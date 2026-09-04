#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    cout << v.capacity() << endl;
    v.push_back(45);
    cout << v.capacity() << endl;
    v.push_back(3);
    cout << v.capacity() << endl;
    v.push_back(21);
    cout << v.capacity() << endl;
    cout << v.size() << endl
         << v.front() << endl
         << v.back() << endl
         << v.at(2) << endl
         << v[2] << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }
    v.pop_back();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }
    v.clear();
    cout << v.size() << endl
         << v.capacity() << endl;
    vector<int> w;
    cout << w.capacity() << endl;
    w.push_back(98);
    w.push_back(34);
    w.push_back(21);
    cout << w.capacity() << endl
         << w.size() << endl;
    w.pop_back();
    w.pop_back();
    cout << w.size() << endl
         << w.capacity() << endl;
    vector<int> u(5, 3);
    for (int i = 0; i < u.size(); i++)
    {
        cout << u.at(i) << endl;
    }
    vector<int> x(u);
    for (int i = 0; i < u.size(); i++)
    {
        cout << u.at(i) << endl;
    }
}