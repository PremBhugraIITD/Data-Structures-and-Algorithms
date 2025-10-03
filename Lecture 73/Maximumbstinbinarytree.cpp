#include <iostream>
#include <queue>
#include <limits.h>
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

class info
{
public:
    int maxi, mini;
    bool isBST;
    int size;
};
info solve(Node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    info currNode;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);
    currNode.size = left.size + right.size + 1;
    if (left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini)
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }
    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }
    return currNode;
}
int largestBST(Node *root)
{
    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}
// TC=O(n)
int main()
{
    Node *root = build_level_order(root);
    // 5 2 4 1 3 -1 -1 -1 -1 -1 -1
    level_order_traversal(root);
    cout << largestBST(root) << endl;
}