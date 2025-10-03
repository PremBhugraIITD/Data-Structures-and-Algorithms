#include <iostream>
#include <vector>
#include <string>
using namespace std;
void Subsequences(string s, string output, int index, vector<string> &ans)
{
    if (index >= s.size())
    {
        ans.push_back(output);
        return;
    }
    else
    {
        Subsequences(s, output, index + 1, ans); // Exclusion
        char character = s[index];
        output += character; // Inclusion
        Subsequences(s, output, index + 1, ans);
    }
}
int main()
{
    vector<string> ans;
    string s;
    getline(cin, s);
    string output = "";
    Subsequences(s, output, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}