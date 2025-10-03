#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data = " << this->data << endl;
    }
};
class Queue
{
public:
    int val;
    Node *queuenode; // queuenode behaves as the head of the
    Queue(int value)
    { // linked list for the queue
        this->val = value;
        this->queuenode = new Node(value);
    }
    bool isEmpty()
    {
        if (this->queuenode == NULL)
        {
            return true;
        }
        return false;
    }
    void enque(int number)
    {
        Node *temp = new Node(number);
        if (this->queuenode == NULL)
        {
            queuenode = temp;
            return;
        }
        Node *temp2 = this->queuenode;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    int deque()
    {
        if (this->queuenode == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node *temp = this->queuenode;
        int ans = this->queuenode->data;
        this->queuenode = temp->next;
        temp->next = NULL;
        delete temp;
        return ans;
    }
    int queue_front()
    {
        if (this->queuenode == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return this->queuenode->data;
    }
};
void print(Queue q)
{
    if (q.queuenode == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *temp = q.queuenode;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Queue q(5);
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