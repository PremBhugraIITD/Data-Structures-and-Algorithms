#include <iostream>
using namespace std;
class Stack
{
public:
    int *arr;
    int n, size;
    int *top;
    int *next;
    int freespot;
    Stack(int n, int size)
    {
        this->n = n;
        this->size = size;
        arr = new int[size];
        top = new int[n];
        next = new int[size];
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
        freespot = 0;
    }
    bool push(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }
        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
        return true;
    }
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
// TC=O(1)
// SC=O(size+n)
int main()
{
    Stack st(6, 3);
    cout << st.push(10, 1) << endl;
    cout << st.push(100, 2) << endl;
    cout << st.push(20, 1) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(2) << endl;
    for (int i = 0; i < st.size; i++)
    {
        cout << st.arr[i] << " ";
    }
}