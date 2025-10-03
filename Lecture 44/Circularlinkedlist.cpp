#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data = " << this->data << endl;
    }
};
void InsertAfterNode(Node *&tail, int prevelement, int d)
{ /*We want to insert d after prevelement assuming prevlement exists
in the list*/
    if (tail == NULL)
    { // For empty list
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Node *current = tail;
        while (current->data != prevelement)
        { // Gets the current node to prevelement
            current = current->next;
        }
        Node *temp = new Node(d);
        temp->next = current->next;
        current->next = temp;
        if (current == tail)
        {
            tail = current->next;
        }
    }
}
void print(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node *temp = tail;
    temp = temp->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << tail->data << endl;
}
void deleteNode(Node *&tail, int value)
{
    Node *previous = tail;
    Node *current = tail->next;
    while (current->data != value)
    { // Current node moves to the position containing the value to be deleted
        current = current->next;
        previous = previous->next;
    }
    if (current == previous)
    { // For single element list
        tail = NULL;
        return;
    }
    previous->next = current->next;
    current->next = NULL;
    if (current == tail)
    {
        tail = previous;
    }
    delete current;
}
int main()
{
    Node *tail = NULL;
    print(tail);
    InsertAfterNode(tail, 5, 10);
    print(tail);
    InsertAfterNode(tail, 10, 7);
    print(tail);
    InsertAfterNode(tail, 7, 12);
    print(tail);
    cout << tail->data << endl;
    InsertAfterNode(tail, 12, 99);
    print(tail);
    InsertAfterNode(tail, 7, 15);
    print(tail);
    InsertAfterNode(tail, 10, 1);
    print(tail);
    cout << tail->data << endl;
    deleteNode(tail, 7);
    print(tail);
    deleteNode(tail, 10);
    print(tail);
    deleteNode(tail, 99);
    print(tail);
    cout << tail->data << endl;
}