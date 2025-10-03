#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> st)
{
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
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int nums = st.top();
    st.pop();
    reverse(st);
    InsertAtBottom(st, nums);
}
int main()
{
    stack<int> st;
    st.push(12);
    st.push(1);
    st.push(43);
    st.push(-89);
    st.push(0);
    print(st);
    cout << endl;
    reverse(st);
    print(st);
}