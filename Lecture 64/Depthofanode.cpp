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

int depth(Node *root, int target)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->data == target)
    {
        return 0;
    }
    else
    {
        int left = depth(root->left, target);
        int right = depth(root->right, target);
        if (left == -1 && right == -1)
        {
            return -1;
        }
        else if (left == -1)
        {
            return right + 1;
        }
        else
        {
            return left + 1;
        }
    }
}

int main()
{
    Node *root = build_level_order(root);
    level_order_traversal(root);
    cout << depth(root, 1) << endl;
    cout << depth(root, 2) << endl;
    cout << depth(root, 3) << endl;
    cout << depth(root, 4) << endl;
    cout << depth(root, 5) << endl;
    cout << depth(root, 6) << endl;
    cout << depth(root, 7) << endl;
    cout << depth(root, 8) << endl;
}

// 1 2 3 4 -1 5 6 -1 -1 7 -1 -1 -1 -1 8 -1 -1