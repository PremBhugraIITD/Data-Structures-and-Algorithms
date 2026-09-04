#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void print(queue<int> q)
{ // Prints queue from front to back
    if (q.empty())
    {
        cout << endl;
        return;
    }
    cout << q.front() << " ";
    q.pop();
    print(q);
}
// Approach 1
void Reverse1(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int num = q.front();
    q.pop();
    Reverse1(q);
    q.push(num);
}
// Approach 2
void Reverse2(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}
int main()
{
    cout << "Approach 1" << endl;
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.push(10);
    print(q);
    Reverse1(q);
    print(q);
    cout << "Approach 2" << endl;
    queue<int> q2;
    q2.push(2);
    q2.push(4);
    q2.push(6);
    q2.push(8);
    q2.push(10);
    print(q2);
    Reverse2(q2);
    print(q2);
}