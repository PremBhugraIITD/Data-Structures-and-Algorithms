#include <iostream>
using namespace std;
class Queue
{
public:
    int front, rear; // rear has the value of the next index of the last element
    int size;
    int *arr;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = 0;
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }
    void enque(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear++] = data;
        }
    }
    int deque()
    {
        if (front == rear)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front++] = -1;
        if (front == rear)
        {                     // If, after dequeing, the queue becomes empty then
            front = rear = 0; // set both front and rear back to their initial
        } // state
        return ans;
    }
    int queue_front()
    {
        if (front == rear)
        {
            return -1;
        }
        return arr[front];
    }
};
void print(Queue q)
{
    if (q.front == q.rear)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = q.front; i < q.rear; i++)
    {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    Queue q(5);
    q.enque(5);
    q.enque(3);
    q.enque(8);
    q.enque(2);
    q.enque(4);
    cout << q.isEmpty() << endl;
    print(q);
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.queue_front() << endl;
    print(q);
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    print(q);
    cout << q.isEmpty() << endl;
}