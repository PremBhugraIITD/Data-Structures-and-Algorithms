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
Node *Merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    Node *previous;
    Node *current;
    Node *temp;
    Node *ans;
    if (head1->data >= head2->data)
    {
        previous = head2;
        current = head2->next;
        temp = head1;
        ans = head2;
    }
    else
    {
        previous = head1;
        current = head1->next;
        temp = head2;
        ans = head1;
    }
    while (current != NULL && temp != NULL)
    {
        if ((temp->data >= previous->data) && (temp->data <= current->data))
        {
            previous->next = temp;
            temp = temp->next;
            previous->next->next = current;
            current = previous->next;
            continue;
        }
        current = current->next;
        previous = previous->next;
    }
    if (current == NULL)
    {
        previous->next = temp;
    }
    return ans;
}
int main()
{
    cout << "First" << endl;
    Node *head1 = new Node(4);
    InsertAtHead(2, head1);
    InsertAtHead(1, head1);
    print(head1);
    Node *head2 = new Node(4);
    InsertAtHead(3, head2);
    InsertAtHead(1, head2);
    print(head2);
    Node *head3 = Merge(head1, head2);
    print(head3);
    cout << "Second" << endl;
    Node *head4 = new Node(9);
    InsertAtHead(2, head4);
    InsertAtHead(2, head4);
    InsertAtHead(1, head4);
    print(head4);
    Node *head5 = new Node(14);
    InsertAtHead(11, head5);
    InsertAtHead(9, head5);
    InsertAtHead(6, head5);
    InsertAtHead(5, head5);
    InsertAtHead(5, head5);
    InsertAtHead(3, head5);
    print(head5);
    Node *head6 = Merge(head4, head5);
    print(head6);
}