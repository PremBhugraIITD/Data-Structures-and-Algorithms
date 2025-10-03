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
void in_order_traversal(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    in_order_traversal(root->left, count);
    in_order_traversal(root->right, count);
}
int leafcount(Node *root)
{
    int count = 0;
    in_order_traversal(root, count);
    return count;
}
int main()
{
    Node *root = build_tree(root);
    level_order_traversal(root);
    cout << leafcount(root) << endl;
}