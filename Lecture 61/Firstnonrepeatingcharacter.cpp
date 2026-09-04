#include <iostream>
#include <queue>
using namespace std;
string NonRepeating(string s)
{
    int arr[26] = {0};
    queue<char> q;
    string ans;
    // q.front() contains the first non repeating character upto i
    for (int i = 0; i < s.length(); i++)
    {
        int n = s[i] - 'a';
        arr[n]++;
        if (arr[n] == 1)
        {
            q.push(s[i]);
        }
        while (!q.empty())
        {
            int num = q.front() - 'a';
            if (arr[num] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        // Queue gets emptied if there is no non repeating character
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << NonRepeating(s) << endl;
}