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
void traverse_left(Node *root)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    { // Because we do not have to print the leaf nodes' value
        return;
    }
    cout << root->data << " ";
    if (root->left)
    {
        traverse_left(root->left);
    }
    else
    {
        traverse_left(root->right);
    }
}
void traverse_leaves(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }
    traverse_leaves(root->left);
    traverse_leaves(root->right);
}
void traverse_right(Node *root)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    { // Because we do not have to print the leaf nodes' value
        return;
    }
    if (root->right)
    {
        traverse_right(root->right);
    }
    else
    {
        traverse_right(root->left);
    }
    cout << root->data << " ";
}
void boundary_traversal(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty Tree" << endl;
    }
    cout << root->data << " ";
    traverse_left(root->left);
    // traverse_leaves(root->left);
    traverse_leaves(root);
    // traverse_leaves(root->right);
    traverse_right(root->right);
}
int main()
{
    Node *root = build_level_order(root);
    level_order_traversal(root);
    boundary_traversal(root);
}