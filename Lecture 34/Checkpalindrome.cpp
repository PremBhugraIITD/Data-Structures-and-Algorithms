#include <iostream>
#include <string>
using namespace std;
bool pallindrome_check(string s, int l, int u)
{
    if (l > u)
    {
        return true;
    }
    else if (s[l] != s[u])
    {
        return false;
    }
    else
    {
        return pallindrome_check(s, ++l, --u);
    }
}
int main()
{
    string name;
    getline(cin, name);
    cout << pallindrome_check(name, 0, name.size() - 1);
}