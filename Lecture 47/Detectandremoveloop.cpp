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
// Approach 1 (Using Map)
bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
/*
TC = O(n)
SC = O(n)
*/
// Approach 2 (Floyd's Cycle Detection)
bool detectLoop2(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            return 1;
        }
    }
    return 0;
}
/*
TC = O(n)
SC = O(1)
*/
// Floyd's Algorithm to find starting node of cycle
Node *startingNode(Node *head)
{
    if (detectLoop2(head) == false)
    {
        cout << "Loop not present" << endl;
        return NULL;
    }
    Node *fast = head;
    Node *slow = head;
    while (true)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    slow = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
    return fast;
}
void removeLoop(Node *head)
{
    if (detectLoop2(head) == false)
    {
        cout << "No need to remove cycle as cycle is absent" << endl;
        return;
    }
    Node *LoopStart = startingNode(head);
    Node *temp = LoopStart;
    while (temp->next != LoopStart)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    cout << "Approach 1" << endl;
    cout << "First" << endl;
    Node *head1 = new Node(8);
    InsertAtHead(7, head1);
    InsertAtHead(6, head1);
    InsertAtHead(5, head1);
    InsertAtHead(4, head1);
    InsertAtHead(3, head1);
    InsertAtHead(2, head1);
    InsertAtHead(1, head1);
    print(head1);
    // To make the tail Node to point to Node with data = 3
    head1->next->next->next->next->next->next->next->next = head1->next->next;
    cout << detectLoop(head1) << endl;
    cout << "Second" << endl;
    Node *head2 = new Node(40);
    InsertAtHead(30, head2);
    InsertAtHead(20, head2);
    InsertAtHead(10, head2);
    print(head2);
    cout << detectLoop(head2) << endl;

    cout << "Approach 2" << endl;
    cout << "First" << endl;
    Node *head3 = new Node(8);
    InsertAtHead(7, head3);
    InsertAtHead(6, head3);
    InsertAtHead(5, head3);
    InsertAtHead(4, head3);
    InsertAtHead(3, head3);
    InsertAtHead(2, head3);
    InsertAtHead(1, head3);
    print(head3);
    head3->next->next->next->next->next->next->next->next = head3->next->next;
    cout << detectLoop2(head3) << endl;
    startingNode(head3);
    removeLoop(head3); // Prints 3 also as detectLoop2 is being used in this function
    cout << detectLoop2(head3) << endl;
    print(head3);
    cout << head3->data << endl;
    cout << "Second" << endl;
    Node *head4 = new Node(40);
    InsertAtHead(30, head4);
    InsertAtHead(20, head4);
    InsertAtHead(10, head4);
    print(head4);
    cout << detectLoop2(head4) << endl;
    startingNode(head4);
    removeLoop(head4);
    cout << detectLoop2(head4) << endl;
    print(head4);
    cout << head4->data << endl;
}