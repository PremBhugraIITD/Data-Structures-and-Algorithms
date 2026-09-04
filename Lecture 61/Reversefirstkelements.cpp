#include <stack>
#include <queue>
#include <iostream>
using namespace std;
void print(queue<int> q)
{ // Prints queue from front to rear
    if (q.empty())
    {
        cout << endl;
        return;
    }
    cout << q.front() << " ";
    q.pop();
    print(q);
}
void ReverseFirstK(queue<int> &q, int k)
{
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < q.size() - k; i++)
    {
        int num = q.front();
        q.pop();
        q.push(num);
    }
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    print(q);
    ReverseFirstK(q, 3);
    print(q);
}