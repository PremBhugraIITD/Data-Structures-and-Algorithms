#include <iostream>
#include <stack>
using namespace std;
/*The opening and closing brackets are redundant if no operator is present between them. The brackets are
still redundant if between them another pair of brackets are present which themselves contain an
operator. In that case, the inner bracktes are not redundant and the outer brackets are redundant.
For example: In ((a+b)) the outer brackets are redundant but the inner ones are not*/
bool redundantBrackets(string s)
{ // Given string already has valid parentheses
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {                // Storing only those characters of the
            st.push(ch); // string which are either any operator
        } // or an openening bracket
        else
        {
            if (ch == ')')
            {
                bool redundant = true;
                while (st.top() != '(')
                {                        // Running a loop throughout the stack which was formed
                    char top = st.top(); // until this closing bracket was found
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        redundant = false; // If any operator is found between the opening
                    } // and closing brackets then those are not redunant
                    st.pop();
                }
                if (redundant == true)
                {
                    return true;
                }
                st.pop(); // Popping the opening bracket too
            }
        }
    }
    return false; // Returning false since no closing bracket was found for which no operator occured
} // before reaching the corresponding opening bracket
int main()
{
    string s;
    cin >> s;
    cout << redundantBrackets(s) << endl;
}