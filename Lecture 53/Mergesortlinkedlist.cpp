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
int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
Node *Split(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    int length = getLength(head);
    int position;
    if (length % 2 == 0)
    {
        position = length / 2;
    }
    else
    {
        position = (length / 2) + 1;
    }
    Node *temp = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    Node *sub_head = temp->next;
    temp->next = NULL;
    return sub_head;
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
Node *MergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *sub_head = Split(head);
    Node *left = MergeSort(head);
    Node *right = MergeSort(sub_head);
    Node *ans = Merge(left, right);
    return ans;
}
int main()
{
    Node *head1 = new Node(0);
    InsertAtHead(4, head1);
    InsertAtHead(3, head1);
    InsertAtHead(5, head1);
    InsertAtHead(-1, head1);
    print(head1);
    Node *head2 = MergeSort(head1);
    print(head2);
    Node *head3 = new Node(6);
    InsertAtHead(12, head3);
    InsertAtHead(55, head3);
    InsertAtHead(55, head3);
    InsertAtHead(63, head3);
    InsertAtHead(-5, head3);
    InsertAtHead(53, head3);
    InsertAtHead(12, head3);
    print(head3);
    Node *head4 = MergeSort(head3);
    print(head4);
}