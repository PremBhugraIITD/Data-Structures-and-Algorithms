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
void sortInsert(stack<int> &sorted, int value)
{ // Inserts a value in sorted order in an already sorted stack
    if (sorted.empty() || !sorted.empty() && sorted.top() <= value)
    {
        sorted.push(value);
        return;
    }
    int num = sorted.top();
    sorted.pop();
    sortInsert(sorted, value);
    sorted.push(num);
}
void Sort(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int num = st.top();
    st.pop();
    Sort(st);
    sortInsert(st, num);
}
int main()
{
    stack<int> st;
    st.push(6);
    st.push(2);
    st.push(10);
    st.push(8);
    st.push(4);
    st.push(0);
    print(st);
    cout << endl;
    Sort(st);
    print(st);
}