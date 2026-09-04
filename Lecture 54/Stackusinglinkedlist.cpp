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
class Stack
{
public:
    int val;
    Node *stacknode; // this->stacknode acts as head
    Stack(int v)
    {                  // for the linked list of the
        this->val = v; // stack
        this->stacknode = new Node(v);
    }
    bool isEmpty()
    {
        if (this->stacknode == NULL)
        {
            return true;
        }
        return false;
    }
    void push(int element)
    {
        Node *temp = new Node(element);
        if (this->stacknode == NULL)
        {
            this->stacknode = temp;
            return;
        }
        Node *temp2 = this->stacknode;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    void pop()
    {
        if (this->stacknode == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        else if (this->stacknode->next == NULL)
        {
            this->stacknode = NULL;
            return;
        }
        Node *temp = this->stacknode;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    int peek()
    {
        if (this->stacknode == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        Node *temp = this->stacknode;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->data;
    }
};
void print(Stack st)
{
    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    Node *temp = st.stacknode;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Stack st(2);
    cout << st.stacknode->data << endl;
    cout << st.peek() << endl;
    st.push(4);
    cout << st.peek() << endl;
    st.push(6);
    st.push(8);
    st.push(10);
    cout << st.peek() << endl;
    print(st);
    st.pop();
    st.pop();
    cout << st.peek() << endl;
    print(st);
    cout << st.isEmpty() << endl;
    st.pop();
    st.pop();
    print(st);
    cout << st.peek() << endl;
    st.pop();
    cout << st.isEmpty() << endl;
    print(st);
    cout << st.peek() << endl;
    st.pop();
    cout << st.val << endl;
}