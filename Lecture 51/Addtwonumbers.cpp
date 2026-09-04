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
void InsertAtTail(int d, Node *&tail)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
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
Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}
Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *temp1 = reverseLinkedList(head1);
    Node *temp2 = reverseLinkedList(head2);
    Node *head = new Node(-1);
    Node *tail = head;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        int sum = carry + temp1->data + temp2->data;
        if (sum < 10)
        {
            InsertAtTail(sum, tail);
            carry = 0;
        }
        else
        {
            InsertAtTail(sum % 10, tail);
            carry = 1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        int sum = carry + temp1->data;
        if (sum < 10)
        {
            InsertAtTail(sum, tail);
            carry = 0;
        }
        else
        {
            InsertAtTail(0, tail);
            carry = 1;
        }
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        int sum = carry + temp2->data;
        if (sum < 10)
        {
            InsertAtTail(sum, tail);
            carry = 0;
        }
        else
        {
            InsertAtTail(0, tail);
            carry = 1;
        }
        temp2 = temp2->next;
    }
    if (carry == 1)
    {
        InsertAtTail(1, tail);
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return reverseLinkedList(head);
}
// TC=O(m+n)
// SC=O(max(m,n)) because a new list has to be made for storing the answer's digits
int main()
{
    cout << "First" << endl;
    Node *head1 = new Node(9);
    InsertAtHead(9, head1);
    InsertAtHead(9, head1);
    InsertAtHead(9, head1);
    InsertAtHead(9, head1);
    print(head1);
    Node *head2 = new Node(9);
    InsertAtHead(9, head2);
    InsertAtHead(9, head2);
    print(head2);
    Node *head3 = addTwoNumbers(head1, head2);
    print(head3);
    cout << "Second" << endl;
    Node *head4 = new Node(5);
    InsertAtHead(1, head4);
    InsertAtHead(2, head4);
    InsertAtHead(9, head4);
    InsertAtHead(5, head4);
    InsertAtHead(5, head4);
    print(head4);
    Node *head5 = new Node(0);
    InsertAtHead(6, head5);
    InsertAtHead(3, head5);
    InsertAtHead(2, head5);
    print(head5);
    Node *head6 = addTwoNumbers(head4, head5);
    print(head6);
}