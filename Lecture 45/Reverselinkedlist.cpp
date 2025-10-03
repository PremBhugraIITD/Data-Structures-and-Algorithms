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
// Approach 1 (Iterative)
Node *reverseLinkedList(Node *&head)
{
    if (head == NULL || head->next == NULL)
    { // If the list had no or single element
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
// Approach 2 (Recursive)
void solve(Node *&head, Node *previous, Node *current)
{
    if (current == NULL)
    {
        head = previous;
        return;
    }
    Node *forward = current->next;
    current->next = previous;
    solve(head, current, forward);
}
Node *reverseLinkedList2(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    solve(head, prev, curr);
    return head;
}
// Approach 3 (Recursive)
Node *reverseLinkedList3(Node *&head)
{
    if (head == NULL || head->next == NULL)
    { // For list of length 0 or 1
        return head;
    }
    Node *sublist_head = reverseLinkedList3(head->next);
    head->next->next = head;
    head->next = NULL;
    return sublist_head;
}
int main()
{
    cout << "Approach 1:" << endl;
    cout << "First" << endl;
    Node *node1 = new Node(10);
    Node *head1 = node1;
    InsertAtHead(23, head1);
    InsertAtHead(12, head1);
    InsertAtHead(45, head1);
    InsertAtHead(1, head1);
    print(head1);
    reverseLinkedList(head1);
    print(head1);
    cout << "Second" << endl;
    Node *head2 = new Node(20);
    InsertAtHead(7, head2);
    InsertAtHead(34, head2);
    InsertAtHead(65, head2);
    print(head2);
    reverseLinkedList(head2);
    print(head2);
    cout << "Approach 2:" << endl;
    cout << "First" << endl;
    Node *node3 = new Node(10);
    Node *head3 = node3;
    InsertAtHead(23, head3);
    InsertAtHead(12, head3);
    InsertAtHead(45, head3);
    InsertAtHead(1, head3);
    print(head3);
    reverseLinkedList2(head3);
    print(head3);
    cout << "Second" << endl;
    Node *head4 = new Node(20);
    InsertAtHead(7, head4);
    InsertAtHead(34, head4);
    InsertAtHead(65, head4);
    print(head4);
    reverseLinkedList2(head4);
    print(head4);
    cout << "Approach 3:" << endl;
    cout << "First" << endl;
    Node *node5 = new Node(10);
    Node *head5 = node5;
    InsertAtHead(23, head5);
    InsertAtHead(12, head5);
    InsertAtHead(45, head5);
    InsertAtHead(1, head5);
    print(head5);
    head5 = reverseLinkedList3(head5);

    print(head5);
    cout << "Second" << endl;
    Node *head6 = new Node(20);
    InsertAtHead(7, head6);
    InsertAtHead(34, head6);
    InsertAtHead(65, head6);
    print(head6);
    head6 = reverseLinkedList3(head6);
    print(head6);
}