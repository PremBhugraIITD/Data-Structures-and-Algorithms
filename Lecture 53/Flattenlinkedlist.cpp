#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};
void InsertAtHead(int d, Node *&head1)
{
    if (head1 == NULL)
    {
        Node *temp = new Node(d);
        head1 = temp;
        return;
    }
    Node *temp = new Node(d);
    temp->next = head1;
    head1 = temp;
}
void print(Node *&head1)
{
    Node *temp = head1;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void InsertChild(int d, Node *&head1, Node *&childhead)
{
    Node *temp = new Node(d);
    temp->child = childhead;
    childhead = temp;
    head1->child = childhead;
}
void printchild(Node *childhead)
{
    Node *temp = childhead;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->child;
    }
    cout << endl;
}
Node *Flatten(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *sub_head = Flatten(head->next);
    Node *childtemp = head;
    while (childtemp->child != NULL)
    {
        childtemp = childtemp->child;
    }
    childtemp->next = sub_head;
    Node *temp = head;
    while (temp != childtemp)
    {
        temp->next = temp->child;
        temp = temp->child;
    }
    return head;
}
int main()
{
    cout << "First" << endl;
    Node *head1 = new Node(29);
    InsertAtHead(18, head1);
    InsertAtHead(8, head1);
    InsertAtHead(1, head1);
    Node *childhead1 = new Node(3);
    head1->child = childhead1;
    InsertChild(2, head1, childhead1);
    Node *childhead2 = new Node(15);
    head1->next->child = childhead2;
    InsertChild(10, head1->next, childhead2);
    Node *childhead3 = new Node(22);
    head1->next->next->child = childhead3;
    print(head1);
    cout << 1 << ":";
    printchild(childhead1);
    cout << 8 << ":";
    printchild(childhead2);
    cout << 18 << ":";
    printchild(childhead3);
    cout << 29 << endl;
    Node *head2 = Flatten(head1);
    print(head1);
    print(head2);
    cout << "Second" << endl;
    Node *head3 = new Node(20);
    InsertAtHead(9, head3);
    InsertAtHead(7, head3);
    InsertAtHead(4, head3);
    InsertAtHead(1, head3);
    Node *childhead4 = new Node(3);
    head3->child = childhead4;
    InsertChild(2, head3, childhead4);
    Node *childhead5 = new Node(6);
    head3->next->child = childhead5;
    InsertChild(5, head3->next, childhead5);
    Node *childhead6 = new Node(8);
    head3->next->next->child = childhead6;
    Node *childhead7 = new Node(12);
    head3->next->next->next->child = childhead7;
    print(head3);
    cout << 1 << ":";
    printchild(childhead4);
    cout << 4 << ":";
    printchild(childhead5);
    cout << 7 << ":";
    printchild(childhead6);
    cout << 9 << ":";
    printchild(childhead7);
    cout << 20 << endl;
    Node *head4 = Flatten(head3);
    print(head3);
    print(head4);
}