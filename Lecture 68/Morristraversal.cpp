#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *build_level_order(Node *root)
{
    queue<Node *> q;
    cout << "Enter data:" << endl;
    int n;
    cin >> n;
    root = new Node(n);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Insertion of left child for " << temp->data << endl;
        int l;
        cin >> l;
        if (l != -1)
        {
            temp->left = new Node(l);
            q.push(temp->left);
        }
        cout << "Insertion of right child for " << temp->data << endl;
        int r;
        cin >> r;
        if (r != -1)
        {
            temp->right = new Node(r);
            q.push(temp->right);
        }
    }
    return root;
}
void level_order_traversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            { // If temp!=NULL
                q.push(temp->left);
            }
            if (temp->right)
            { // If temp!=NULL
                q.push(temp->right);
            }
        }
    }
}
void Morris_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *pre;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = curr; // Creation of temporary link
                curr = curr->left;
            }
            else
            {
                pre->right = NULL; // Breaking of the temporary link
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}
int main()
{
    Node *root = build_level_order(root);
    // 1 3 7 4 9 7 -1 -1 -1 -1 -1 -1 -1
    // Output = 4 3 9 1 7 7
    level_order_traversal(root);
    cout << "Morris inorder traversal" << endl;
    Morris_traversal(root);
}