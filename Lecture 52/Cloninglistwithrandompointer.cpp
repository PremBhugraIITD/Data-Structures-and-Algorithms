#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        if (this->random != NULL)
        {
            delete random;
            this->random = NULL;
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
// Approach 1
Node *copyRandomlist(Node *head)
{
    Node *anshead = new Node(-1);
    Node *anstail = anshead;
    Node *temp = head;
    while (temp != NULL)
    {
        InsertAtTail(temp->data, anstail);
        temp = temp->next;
    }
    Node *mark = anshead;
    anshead = anshead->next;
    mark->next = NULL;
    mark->random = NULL;
    delete mark;

    Node *tempOriginal = head;
    Node *tempCloned = anshead;
    while (tempOriginal != NULL && tempCloned != NULL)
    {
        int count = 1;
        Node *temp1 = head;
        while (temp1 != tempOriginal->random)
        {
            temp1 = temp1->next;
            count++;
        }
        Node *temp2 = anshead;
        for (int i = 1; i < count; i++)
        {
            temp2 = temp2->next;
        }
        tempCloned->random = temp2;
        tempOriginal = tempOriginal->next;
        tempCloned = tempCloned->next;
    }
    return anshead;
}
// TC=O(n^2)
// SC=O(1)
// Approach 2
Node *copyRandomlist2(Node *head)
{
    Node *anshead = new Node(-1);
    Node *anstail = anshead;
    Node *temp = head;
    while (temp != NULL)
    {
        InsertAtTail(temp->data, anstail);
        temp = temp->next;
    }
    Node *mark = anshead;
    anshead = anshead->next;
    mark->next = NULL;
    mark->random = NULL;
    delete mark;

    unordered_map<Node *, Node *> old_to_new;
    temp = head;
    Node *temp2 = anshead;
    while (temp != NULL && temp2 != NULL)
    {
        old_to_new[temp] = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }

    temp = head;
    temp2 = anshead;
    while (temp != NULL && temp2 != NULL)
    {
        temp2->random = old_to_new[temp->random];
        temp = temp->next;
        temp2 = temp2->next;
    }
    return anshead;
}
// TC=O(n)
// SC=O(n)
// Approach 3
Node *copyRandomlist3(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    // Copying the original list along with next pointers of each node. Random pointer of each node in the copied list points to NULL
    Node *anshead = new Node(-1);
    Node *anstail = anshead;
    Node *temp = head;
    while (temp != NULL)
    {
        InsertAtTail(temp->data, anstail);
        temp = temp->next;
    }
    Node *mark = anshead;
    anshead = anshead->next;
    mark->next = NULL;
    mark->random = NULL;
    delete mark;
    // Linking the original and copied list together
    Node *curr = head;
    Node *forward = curr;
    temp = anshead;
    Node *tempnext = temp;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = temp;
        tempnext = temp->next;
        temp->next = forward;
        temp = tempnext;
        curr = forward;
    }
    // Making the random pointers of the copied list point towards the next of the random pointers of each copied node
    Node *tempOriginal = head;
    Node *tempCloned = anshead;
    while (true)
    {
        if (tempOriginal->random == NULL)
        {
            tempCloned->random = NULL;
        }
        else
        {
            tempCloned->random = tempOriginal->random->next;
        }
        tempOriginal = tempOriginal->next->next;
        if (tempOriginal == NULL)
        {
            break;
        }
        tempCloned = tempCloned->next->next;
    }
    // Breaking the two lists
    tempOriginal = head;
    tempCloned = anshead;
    while (tempCloned->next != NULL)
    {
        tempOriginal->next = tempOriginal->next->next;
        tempOriginal = tempOriginal->next;
        tempCloned->next = tempCloned->next->next;
        tempCloned = tempCloned->next;
    }
    tempOriginal->next = NULL;
    return anshead;
}
// TC=O(n)
// SC=O(1)
int main()
{
    cout << "Approach1" << endl;
    cout << "First" << endl;
    Node *head1 = new Node(1);
    InsertAtHead(10, head1);
    InsertAtHead(11, head1);
    InsertAtHead(13, head1);
    InsertAtHead(7, head1);
    head1->random = NULL;
    head1->next->random = head1;
    head1->next->next->random = head1->next->next->next->next;
    head1->next->next->next->random = head1->next->next;
    head1->next->next->next->next->random = head1;
    print(head1);
    cout << "Pointer assignemnt:" << endl;
    cout << head1->data << ":" << "NULL" << endl;
    cout << head1->next->data << ":" << head1->next->random->data << endl;
    cout << head1->next->next->data << ":" << head1->next->next->random->data << endl;
    cout << head1->next->next->next->data << ":" << head1->next->next->next->random->data << endl;
    cout << head1->next->next->next->next->data << ":" << head1->next->next->next->next->random->data << endl;
    Node *head2 = copyRandomlist(head1);
    print(head2);
    cout << "Pointer assignemnt:" << endl;
    cout << head2->data << ":" << "NULL" << endl;
    cout << head2->next->data << ":" << head2->next->random->data << endl;
    cout << head2->next->next->data << ":" << head2->next->next->random->data << endl;
    cout << head2->next->next->next->data << ":" << head2->next->next->next->random->data << endl;
    cout << head2->next->next->next->next->data << ":" << head2->next->next->next->next->random->data << endl;
    cout << "Second" << endl;
    Node *head3 = new Node(2);
    InsertAtHead(1, head3);
    head3->random = head3->next;
    head3->next->random = head3->next;
    print(head3);
    cout << "Pointer assignemnt:" << endl;
    cout << head3->data << ":" << head3->random->data << endl;
    cout << head3->next->data << ":" << head3->next->random->data << endl;
    Node *head4 = copyRandomlist(head3);
    print(head4);
    cout << "Pointer assignemnt:" << endl;
    cout << head4->data << ":" << head4->random->data << endl;
    cout << head4->next->data << ":" << head4->next->random->data << endl;
    cout << "Approach2" << endl;
    cout << "First" << endl;
    Node *head5 = new Node(1);
    InsertAtHead(10, head5);
    InsertAtHead(11, head5);
    InsertAtHead(13, head5);
    InsertAtHead(7, head5);
    head5->random = NULL;
    head5->next->random = head5;
    head5->next->next->random = head5->next->next->next->next;
    head5->next->next->next->random = head5->next->next;
    head5->next->next->next->next->random = head5;
    print(head5);
    cout << "Pointer assignemnt:" << endl;
    cout << head5->data << ":" << "NULL" << endl;
    cout << head5->next->data << ":" << head5->next->random->data << endl;
    cout << head5->next->next->data << ":" << head5->next->next->random->data << endl;
    cout << head5->next->next->next->data << ":" << head5->next->next->next->random->data << endl;
    cout << head5->next->next->next->next->data << ":" << head5->next->next->next->next->random->data << endl;
    Node *head6 = copyRandomlist2(head5);
    print(head6);
    cout << "Pointer assignemnt:" << endl;
    cout << head6->data << ":" << "NULL" << endl;
    cout << head6->next->data << ":" << head6->next->random->data << endl;
    cout << head6->next->next->data << ":" << head6->next->next->random->data << endl;
    cout << head6->next->next->next->data << ":" << head6->next->next->next->random->data << endl;
    cout << head6->next->next->next->next->data << ":" << head6->next->next->next->next->random->data << endl;
    cout << "Second" << endl;
    Node *head7 = new Node(2);
    InsertAtHead(1, head7);
    head7->random = head7->next;
    head7->next->random = head7->next;
    print(head7);
    cout << "Pointer assignemnt:" << endl;
    cout << head7->data << ":" << head7->random->data << endl;
    cout << head7->next->data << ":" << head7->next->random->data << endl;
    Node *head8 = copyRandomlist2(head7);
    print(head8);
    cout << "Pointer assignemnt:" << endl;
    cout << head8->data << ":" << head8->random->data << endl;
    cout << head8->next->data << ":" << head8->next->random->data << endl;
    cout << "Approach3" << endl;
    cout << "First" << endl;
    Node *head9 = new Node(1);
    InsertAtHead(10, head9);
    InsertAtHead(11, head9);
    InsertAtHead(13, head9);
    InsertAtHead(7, head9);
    head9->random = NULL;
    head9->next->random = head9;
    head9->next->next->random = head9->next->next->next->next;
    head9->next->next->next->random = head9->next->next;
    head9->next->next->next->next->random = head9;
    print(head9);
    cout << "Pointer assignemnt:" << endl;
    cout << head9->data << ":" << "NULL" << endl;
    cout << head9->next->data << ":" << head9->next->random->data << endl;
    cout << head9->next->next->data << ":" << head9->next->next->random->data << endl;
    cout << head9->next->next->next->data << ":" << head9->next->next->next->random->data << endl;
    cout << head9->next->next->next->next->data << ":" << head9->next->next->next->next->random->data << endl;
    Node *head10 = copyRandomlist3(head9);
    print(head10);
    cout << "Pointer assignemnt:" << endl;
    cout << head10->data << ":" << "NULL" << endl;
    cout << head10->next->data << ":" << head10->next->random->data << endl;
    cout << head10->next->next->data << ":" << head10->next->next->random->data << endl;
    cout << head10->next->next->next->data << ":" << head10->next->next->next->random->data << endl;
    cout << head10->next->next->next->next->data << ":" << head10->next->next->next->next->random->data << endl;
    cout << "Second" << endl;
    Node *head11 = new Node(2);
    InsertAtHead(1, head11);
    head11->random = head11->next;
    head11->next->random = head11->next;
    print(head11);
    cout << "Pointer assignemnt:" << endl;
    cout << head11->data << ":" << head11->random->data << endl;
    cout << head11->next->data << ":" << head11->next->random->data << endl;
    Node *head12 = copyRandomlist3(head11);
    print(head12);
    cout << "Pointer assignemnt:" << endl;
    cout << head12->data << ":" << head12->random->data << endl;
    cout << head12->next->data << ":" << head12->next->random->data << endl;
}