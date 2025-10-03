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
void removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *temp2 = temp;
        while (temp2 != NULL)
        {
            if (temp2->next != NULL && temp2->next->data == temp->data)
            {
                Node *mark = temp2->next;
                temp2->next = mark->next;
                mark->next = NULL;
                delete mark;
                continue;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}
// TC=O(n^2)
// SC=O(1)
int main()
{
    cout << "First" << endl;
    Node *head1 = new Node(3);
    InsertAtHead(2, head1);
    InsertAtHead(4, head1);
    InsertAtHead(3, head1);
    InsertAtHead(2, head1);
    InsertAtHead(3, head1);
    print(head1);
    removeDuplicates(head1);
    print(head1);
    cout << "Second" << endl;
    Node *head2 = new Node(2);
    InsertAtHead(2, head2);
    InsertAtHead(4, head2);
    InsertAtHead(5, head2);
    InsertAtHead(2, head2);
    InsertAtHead(4, head2);
    print(head2);
    removeDuplicates(head2);
    print(head2);
    cout << "Third" << endl;
    Node *head3 = new Node(3);
    InsertAtHead(3, head3);
    InsertAtHead(2, head3);
    InsertAtHead(1, head3);
    InsertAtHead(1, head3);
    print(head3);
    removeDuplicates(head3);
    print(head3);
}