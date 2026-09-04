#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for node with data = " << this->data << endl;
    }
};
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void InsertAtHead(int d, Node *&head)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void InsertAtTail(int d, Node *&tail)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void InsertAtMiddle(int d, int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        InsertAtHead(d, head);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        InsertAtTail(d, tail);
        return;
    }
    Node *nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    nodeToinsert->prev = temp;
    temp->next = nodeToinsert;
    nodeToinsert->next->prev = nodeToinsert;
}
void deleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        Node *current = head;
        Node *previous = NULL;
        int count = 1;
        while (count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }
        if (current->next == NULL)
        {
            previous->next = NULL;
            tail = previous;
            current->prev = NULL;
            delete current;
            return;
        }
        previous->next = current->next;
        current->next->prev = previous;
        current->next = NULL;
        current->prev = NULL;
        delete current;
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    cout << length(head) << endl;
    InsertAtHead(19, head);
    print(head);
    InsertAtTail(23, tail);
    print(head);
    InsertAtMiddle(50, 3, head, tail);
    print(head);
    InsertAtMiddle(25, 1, head, tail);
    print(head);
    InsertAtMiddle(34, 6, head, tail);
    print(head);
    InsertAtMiddle(2, 1, head, tail);
    print(head);
    cout << length(head) << endl;
    cout << head->data << " " << tail->data << endl;
    deleteNode(1, head, tail);
    print(head);
    deleteNode(6, head, tail);
    print(head);
    deleteNode(4, head, tail);
    print(head);
    cout << head->data << " " << tail->data << endl;
}