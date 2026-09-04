#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int *next;
    int *front, *rear;
    int freespot;
    int n, size;
    Queue(int size, int n)
    {
        this->n = n;
        this->size = size;
        arr = new int[size];
        next = new int[size];
        front = new int[n];
        rear = new int[n];
        for (int i = 0; i < n; i++)
        {
            front[i] = rear[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
        freespot = 0;
    }
    bool enque(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }
        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        if (front[m - 1] == -1)
        {
            front[m - 1] = index;
        }
        else
        {
            next[rear[m - 1]] = index;
        }
        next[index] = -1;
        rear[m - 1] = index;
        return true;
    }
    int deque(int m)
    {
        if (front[m - 1] == -1)
        {
            return -1;
        }
        int index = front[m - 1];
        front[m - 1] = next[index];
        if (front[m - 1] == -1)
        {
            rear[m - 1] = -1;
        }
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
int main()
{
    Queue q(9, 3);
    cout << q.enque(10, 1) << endl;
    cout << q.enque(20, 1) << endl;
    cout << q.enque(100, 2) << endl;
    cout << q.enque(30, 1) << endl;
    cout << q.enque(200, 2) << endl;
    cout << q.deque(2) << endl;
    cout << q.deque(1) << endl;
    cout << q.deque(2) << endl;
    cout << q.deque(2) << endl;
    for (int i = 0; i < q.size; i++)
    {
        cout << q.arr[i] << " ";
    }
    cout << endl
         << q.rear[1] << endl;
    cout << q.rear[0] << endl;
}