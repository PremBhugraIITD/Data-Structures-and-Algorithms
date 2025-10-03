#include <iostream>
using namespace std;
class MyCircularQueue
{
    int front;
    int rear; // rear contains the index of the last element
    int size;
    int *arr;

public:
    MyCircularQueue(int k)
    {
        this->size = k;
        arr = new int[k];
        front = rear = -1;
    }
    bool enQueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    bool deQueue()
    {
        if (front == -1)
        {
            return false;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
        return true;
    }
    int Front()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }
    int Rear()
    {
        if (rear == -1)
        {
            return -1;
        }
        return arr[rear];
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            return true;
        }
        return false;
    }
};
int main()
{
    MyCircularQueue q(6);
    cout << q.enQueue(4) << endl;
    cout << q.enQueue(8) << endl;
    cout << q.enQueue(12) << endl;
    ;
    cout << q.enQueue(16) << endl;
    ;
    cout << q.enQueue(20) << endl;
    ;
    cout << q.enQueue(24) << endl;
    cout << q.enQueue(28) << endl;
    cout << q.isFull() << " " << q.isEmpty() << endl;
    cout << q.Front() << " " << q.Rear() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.isFull() << " " << q.isEmpty() << endl;
    cout << q.Front() << " " << q.Rear() << endl;
    cout << q.enQueue(0) << endl;
    cout << q.enQueue(2) << endl;
    cout << q.Front() << " " << q.Rear() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.isFull() << " " << q.isEmpty() << endl;
}