#include <iostream>
using namespace std;
class Stack
{
public:
    int *arr;
    int top1, top2;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    void push1(int element)
    {
        if (top1 == size - 1 || top2 == 0 || top2 - top1 == 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top1] = element;
    }
    void push2(int element)
    {
        if (top1 == size - 1 || top2 == 0 || top2 - top1 == 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[--top2] = element;
    }
    int pop1()
    {
        if (top1 == -1 || top2 == 0)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top1--];
    }
    int pop2()
    {
        if (top1 == size - 1 || top2 == size)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top2++];
    }
};
void print(Stack st)
{
    if (st.top1 == -1 && st.top2 == st.size)
    {
        cout << "Stack is empty" << endl;
    }
    for (int i = 0; i <= st.top1; i++)
    {
        cout << st.arr[i] << " ";
    }
    for (int j = st.top2; j < st.size; j++)
    {
        cout << st.arr[j] << " ";
    }
    cout << endl;
}
int main()
{
    Stack st(10);
    st.push1(2);
    st.push1(4);
    st.push1(6);
    st.push2(1);
    st.push2(3);
    st.push2(5);
    st.push2(7);
    print(st);
    st.push2(9);
    st.push2(11);
    st.push2(13);
    st.push1(8);
    print(st);
    cout << st.pop1() << " " << st.pop2() << endl;
    print(st);
}