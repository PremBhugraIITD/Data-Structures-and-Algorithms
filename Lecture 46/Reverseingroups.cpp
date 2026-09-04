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
Node *reverseKgroups(Node *&head, int k)
{
    if (head == NULL)
    {                // This base case comes into play if the length of the list is a multiple of k and there are
        return head; // no elements which should not be reversed, i.e., forward node reaches the end of the list
    } // and then finally points towards NULL.
    // Reversing first k nodes
    int count = 0;
    Node *forward = head;
    Node *current = head;
    Node *previous = NULL;
    Node *temp = head;
    int track = 0;
    while (temp != NULL && track < k)
    {                      // This loop comes into play if the length of list is not a multiple of k there are
        temp = temp->next; // some elements should not be reversed.
        track++;
    }
    if (temp == NULL && track < k)
    {
        return head;
    }
    while (count < k && current != NULL)
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
        count++;
    }
    // Recursive call for the rest of the linked list
    head->next = reverseKgroups(forward, k);
    head = previous;
    return head;
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
    reverseKgroups(head1, 2);
    print(head1);
    reverseKgroups(head1, 3);
    print(head1);
    cout << "Second" << endl;
    Node *head2 = new Node(20);
    InsertAtHead(7, head2);
    InsertAtHead(34, head2);
    InsertAtHead(65, head2);
    print(head2);
    reverseKgroups(head2, 4);
    print(head2);
}