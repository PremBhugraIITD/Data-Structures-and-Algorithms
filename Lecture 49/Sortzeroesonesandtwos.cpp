#include <iostream>
#include <map>
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
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void InsertAtTail(int d, Node *&tail)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
// Approach 1 (Replacing data)
Node *Sort(Node *head)
{
    Node *temp = head;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            count0++;
        }
        else if (temp->data == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (count0 != 0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1 != 0)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
        }
        temp = temp->next;
    }
    return head;
}
// Approach 2 (Merging three linked lists)
Node *Sort2(Node *&head)
{
    // Making dummy nodes with data -1 for each.
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *current = head;
    while (current != NULL)
    {
        int value = current->data;
        if (value == 0)
        {
            InsertAtTail(0, zeroTail);
        }
        else if (value == 1)
        {
            InsertAtTail(1, oneTail);
        }
        else
        {
            InsertAtTail(2, twoTail);
        }
        current = current->next;
    }
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
        head = zeroHead->next;
        zeroHead->next = NULL;
        oneHead->next = NULL;
        twoHead->next = NULL;
        delete zeroHead, oneHead, twoHead;
        return head;
    }
    // If oneHead does not have elements besides -1
    zeroTail->next = twoHead->next;
    head = zeroHead->next;
    zeroHead->next = NULL;
    twoHead->next = NULL;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}
int main()
{
    cout << "Approach 1" << endl;
    Node *head1 = new Node(1);
    InsertAtHead(1, head1);
    InsertAtHead(0, head1);
    InsertAtHead(2, head1);
    InsertAtHead(1, head1);
    InsertAtHead(2, head1);
    InsertAtHead(0, head1);
    InsertAtHead(1, head1);
    print(head1);
    Sort(head1);
    print(head1);
    cout << "Approach 2" << endl;
    cout << "First" << endl;
    Node *head2 = new Node(1);
    InsertAtHead(1, head2);
    InsertAtHead(0, head2);
    InsertAtHead(2, head2);
    InsertAtHead(1, head2);
    InsertAtHead(2, head2);
    InsertAtHead(0, head2);
    InsertAtHead(1, head2);
    print(head2);
    Sort2(head2);
    print(head2);
    cout << "Second" << endl;
    Node *head3 = new Node(0);
    InsertAtHead(0, head3);
    InsertAtHead(2, head3);
    InsertAtHead(0, head3);
    InsertAtHead(2, head3);
    InsertAtHead(2, head3);
    InsertAtHead(0, head3);
    print(head3);
    Sort2(head3);
    print(head3);
}