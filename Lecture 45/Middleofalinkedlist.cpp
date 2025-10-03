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
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else if (head->next->next == NULL)
    {
        return head->next;
    }
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
int main()
{
    cout << "First" << endl;
    Node *node1 = new Node(10);
    Node *head1 = node1;
    InsertAtHead(23, head1);
    InsertAtHead(12, head1);
    InsertAtHead(45, head1);
    InsertAtHead(1, head1);
    print(head1);
    cout << findMiddle(head1)->data << endl;
    cout << "Second" << endl;
    Node *head2 = new Node(20);
    InsertAtHead(7, head2);
    InsertAtHead(34, head2);
    InsertAtHead(65, head2);
    print(head2);
    cout << findMiddle(head2)->data << endl;
}