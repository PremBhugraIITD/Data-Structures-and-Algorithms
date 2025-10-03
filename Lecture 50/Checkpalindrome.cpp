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
// Index of middle = n/2 if n is even and (n/2)+1 when n is odd in 1 based indexing
Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *curr = head;
        Node *forward = head;
        Node *prev = NULL;
        while (curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
}

bool isPalindrome(Node *head)
{
    Node *middle = findMiddle(head);
    middle->next = reverse(middle->next);
    Node *temp1 = head;
    Node *temp2 = middle->next;
    while (temp2)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    middle->next = reverse(middle->next);
    return true;
}
int main()
{
    cout << "First" << endl;
    Node *head1 = new Node(7);
    InsertAtHead(6, head1);
    InsertAtHead(5, head1);
    InsertAtHead(4, head1);
    InsertAtHead(3, head1);
    InsertAtHead(2, head1);
    InsertAtHead(1, head1);
    print(head1);
    cout << isPalindrome(head1) << endl;
    cout << "Second" << endl;
    Node *head2 = new Node(3);
    InsertAtHead(6, head2);
    InsertAtHead(7, head2);
    InsertAtHead(7, head2);
    InsertAtHead(6, head2);
    InsertAtHead(3, head2);
    print(head2);
    cout << isPalindrome(head2) << endl;
    cout << "Third" << endl;
    Node *head3 = new Node(3);
    InsertAtHead(6, head3);
    InsertAtHead(7, head3);
    InsertAtHead(4, head3);
    InsertAtHead(7, head3);
    InsertAtHead(6, head3);
    InsertAtHead(3, head3);
    print(head3);
    cout << isPalindrome(head3) << endl;
}