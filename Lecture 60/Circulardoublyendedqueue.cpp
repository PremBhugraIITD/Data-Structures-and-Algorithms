#include <iostream>
using namespace std;
class Deque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool pushFront(int x)
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
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
        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }

    int popRear()
    {
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
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
    Deque d(6);
    cout << d.pushFront(2) << endl;
    cout << d.pushFront(4) << endl;
    cout << d.pushRear(20) << endl;
    cout << d.pushRear(40) << endl;
    cout << d.pushFront(6) << endl;
    cout << d.pushRear(60) << endl;
    cout << d.pushFront(8) << endl;
    cout << d.pushRear(80) << endl;
    cout << d.isFull() << " " << d.isEmpty() << endl;
    cout << d.popFront() << endl;
    cout << d.popRear() << endl;
    cout << d.isFull() << " " << d.isEmpty() << endl;
    cout << d.getFront() << " " << d.getRear() << endl;
    cout << d.popFront() << endl;
    cout << d.popFront() << endl;
    cout << d.popRear() << endl;
    cout << d.popRear() << endl;
    cout << d.popFront() << endl;
    cout << d.popRear() << endl;
    cout << d.isFull() << " " << d.isEmpty() << endl;
    cout << d.getFront() << " " << d.getRear() << endl;
}