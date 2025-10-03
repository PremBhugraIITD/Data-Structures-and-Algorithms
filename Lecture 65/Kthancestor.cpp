#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
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
Node *ancestor_k(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == node)
    {
        return root;
    }
    Node *left = ancestor_k(root->left, k, node);
    Node *right = ancestor_k(root->right, k, node);
    if (left != NULL && right == NULL)
    {
        k--;
        if (k == 0)
        {
            k = INT_MAX; // It is done so that the function, once being implemented for root, does not get implemented again for root->left and root->right
            return root;
        }
        return left;
    }
    else if (left == NULL && right != NULL)
    {
        k--;
        if (k == 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}
// TC=O(n)
// SC=O(h)
int main()
{
    Node *root = build_level_order(root);
    level_order_traversal(root);
    int k = 3;
    cout << ancestor_k(root, k, 9)->data << endl;
}