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
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (max(left_height, right_height) + 1);
}
// TC=O(n), n = Number of nodes
// SC=O(h), h = Height of tree
int main()
{
    Node *root = build_level_order(root);
    level_order_traversal(root);
    cout << "Height: " << height(root) << endl;
}