#include <iostream>
#include <queue>
using namespace std;
#include <iostream>
#include <queue>
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
int count_nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
        ;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}
// TC=O(n)
// SC=O(h)
bool isCBT(Node *root, int i, int count)
{
    if (root == NULL)
    {
        return true;
    }
    else if (i >= count)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, 2 * i + 1, count);
        bool right = isCBT(root->right, 2 * i + 2, count);
        return (left && right);
    }
}
// TC=O(n)
// SC=O(h)
bool isMaxorder(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxorder(root->left);
        bool right = isMaxorder(root->right);
        return (left && right && root->data > root->left->data && root->data > root->right->data);
    }
}
// TC=O(n)
// SC=O(h)
bool isHeap(Node *root)
{
    int i = 0;
    int n = count_nodes(root);
    if (isCBT(root, i, n) && isMaxorder(root))
    {
        return true;
    }
    return false;
}
// TC=O(n)
// SC=O(h)
int main()
{
    Node *root = build_level_order(root);
    level_order_traversal(root);
    cout << isHeap(root) << endl;
}