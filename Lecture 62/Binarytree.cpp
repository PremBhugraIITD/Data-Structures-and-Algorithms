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
Node *build_tree(Node *root)
{
    cout << "Enter data:" << endl;
    int n;
    cin >> n;
    root = new Node(n);
    if (n == -1)
    {
        return NULL;
    }
    cout << "Insertion of left child for " << root->data << endl;
    root->left = build_tree(root->left);
    cout << "Insertion of right child for " << root->data << endl;
    root->right = build_tree(root->right);
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
void in_order_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order_traversal(root->left);
    cout << root->data << " ";
    in_order_traversal(root->right);
}
void pre_order_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}
void post_order_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    root = build_tree(root);
    // 1 3 4 -1 -1 9 -1 -1 7 7 -1 -1 -1
    cout << "Level order" << endl;
    level_order_traversal(root);
    cout << "In order" << endl;
    in_order_traversal(root);
    cout << endl
         << "Pre order" << endl;
    pre_order_traversal(root);
    cout << endl
         << "Post order" << endl;
    post_order_traversal(root);
}