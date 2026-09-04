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
void InsertAtHead(int d, Node *&head)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void InsertAtTail(int d, Node *&tail)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void InsertAtMiddle(int d, int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {                          // Without this if block, the element to be inserted at postion 1
        InsertAtHead(d, head); // is inserted at postion 2.
        return;
    }
    Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    { // This loops takes temp to position - 1 in 1 based index
        temp = temp->next;
    }
    if (temp->next == NULL)
    { // To take care of tail if you want to insert any element to the end of the list
        InsertAtTail(d, tail);
        return;
    }
    Node *nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}
void deleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
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
            delete current;
            return;
        }
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}
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
int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << " " << node1->next << endl;
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(12, head);
    print(head);
    InsertAtHead(15, head);
    print(head);
    InsertAtTail(23, tail);
    InsertAtTail(25, tail);
    print(head);
    InsertAtMiddle(7, 3, head, tail);
    print(head);
    InsertAtMiddle(20, 1, head, tail);
    print(head);
    InsertAtMiddle(1, 8, head, tail);
    print(head);
    InsertAtTail(99, tail);
    print(head);
    deleteNode(6, head, tail);
    print(head);
    deleteNode(1, head, tail);
    print(head);
    deleteNode(7, head, tail);
    print(head);
    cout << "Head: " << head->data << " Tail: " << tail->data << endl;
    delete head;
}