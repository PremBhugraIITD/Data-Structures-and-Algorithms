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
};
void InsertAtHead(int d, Node *&head)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        return;
    }
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void print(Node *&head)
{ // For printing singly linked list
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print2(Node *&head)
{ // For printing the circular linked list
    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
bool isCircular(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "Linked list is circular" << endl; // Assume empty linked list as circular
        return true;
    }
    temp = temp->next;
    while (true)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "Not circular" << endl;
            return false;
        }
        else if (temp == head)
        {
            cout << "Circular" << endl;
            return true;
        }
    }
}
int main()
{
    cout << "First" << endl;
    Node *node1 = new Node(8);
    Node *head1 = node1;
    InsertAtHead(7, head1);
    InsertAtHead(6, head1);
    InsertAtHead(5, head1);
    InsertAtHead(4, head1);
    InsertAtHead(3, head1);
    InsertAtHead(2, head1);
    InsertAtHead(1, head1);
    print(head1);
    isCircular(head1);
    cout << "Second" << endl;
    Node *node2 = new Node(50);
    Node *head2 = node2;
    InsertAtHead(40, head2);
    InsertAtHead(30, head2);
    InsertAtHead(20, head2);
    InsertAtHead(10, head2);
    node2->next = head2; // Makes the second linked list circular
    print2(head2);
    isCircular(head2);
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}