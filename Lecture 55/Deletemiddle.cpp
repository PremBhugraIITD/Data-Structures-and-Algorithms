#include <iostream>
#include <stack>
using namespace std;
void deleteMiddle(stack<int> &st, int size, int count = 0)
{
    if (count == size / 2)
    {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    deleteMiddle(st, size, count + 1);
    st.push(num);
}
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
int main()
{
    cout << "First" << endl;
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(6);
    st.push(8);
    st.push(10);
    print(st);
    deleteMiddle(st, 5);
    cout << endl;
    print(st);
    cout << endl
         << "Second" << endl;
    stack<int> st2;
    st2.push(1);
    st2.push(3);
    st2.push(5);
    st2.push(9);
    print(st2);
    deleteMiddle(st2, 4);
    cout << endl;
    print(st2);
}