#include <iostream>
#include <stack>
using namespace std;
int MinReversal(string s)
{
    if (s.length() % 2 != 0)
    {
        return -1;
    }
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() && st.top() == '{' && s[i] == '}')
        {
            st.pop();
            continue;
        }
        else
        {
            st.push(s[i]);
        }
    }
    // Now the stack contains only invalid parentheses
    int ans = 0;
    while (!st.empty())
    {
        char top1 = st.top();
        st.pop();
        char top2 = st.top();
        st.pop();
        if (top1 == top2)
        { // It means that top1 = top2 ='{' or '}'
            ans += 1;
        }
        else
        {
            ans += 2; // It means that top1 = '{' and top2 = '}'
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << MinReversal(s) << endl;
}