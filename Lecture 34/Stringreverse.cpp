#include <iostream>
#include <string>
using namespace std;
void string_reverse(string &s, int l, int u)
{

    if (l > u)
    {
        return;
    }
    else
    {
        swap(s[l], s[u]);
        string_reverse(s, ++l, --u);
    }
}
int main()
{
    string name;
    getline(cin, name);
    string_reverse(name, 0, name.size() - 1);
    cout << name << endl;
}