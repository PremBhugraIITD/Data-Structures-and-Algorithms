#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> st)
{ // Prints stack from bottom to top
    if (st.empty())
    {
        return;
    }
    int num = st.top();
    st.pop();
    print(st);
    cout << num << " ";
    st.push(num);
}
void InsertAtBottom(stack<int> &st, int value)
{
    if (st.empty())
    {
        st.push(value);
        return;
    }
    int num = st.top();
    st.pop();
    InsertAtBottom(st, value);
    st.push(num);
}
int main()
{
    stack<int> st;
    st.push(2);
    st.push(12);
    st.push(22);
    print(st);
    cout << endl;
    InsertAtBottom(st, 0);
    InsertAtBottom(st, -8);
    print(st);
}