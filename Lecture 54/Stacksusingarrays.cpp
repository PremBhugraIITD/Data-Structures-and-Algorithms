#include <iostream>
using namespace std;
class Stack
{
public:
    int top;
    int *arr;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = element;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};
void print(Stack st)
{
    if (st.top == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = 0; i <= st.top; i++)
    {
        cout << st.arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    Stack st(5);
    cout << st.top << endl;
    st.push(3);
    cout << st.top << endl;
    st.push(6);
    cout << st.top << endl;
    st.push(9);
    cout << st.top << endl;
    st.push(12);
    cout << st.top << endl;
    cout << st.peek() << endl;
    cout << st.isEmpty() << endl;
    print(st);
    st.pop();
    cout << st.top << endl;
    st.pop();
    cout << st.top << endl;
    cout << st.peek() << endl;
    print(st);
    st.pop();
    st.pop();
    cout << st.top << endl;
    cout << st.peek() << endl;
    st.pop();
    cout << st.isEmpty() << endl;
    print(st);
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(11);
}