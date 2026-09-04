#include <iostream>
#include <queue>
#include <map>
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
void top_view(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    map<int, pair<bool, int>> nodes; // The first block stores the column number, the second one depicts whether the column already contains an entry or not and the third one contains the node value.
    // Map is sorted according to column number
    queue<pair<Node *, int>> q; // The first block stores the node and the second one stores the column number.
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *front_node = temp.first;
        int column = temp.second;
        if (nodes[column].first != true)
        {
            nodes[column].first = true;
            nodes[column].second = front_node->data;
        }
        if (front_node->left)
        {
            q.push(make_pair(front_node->left, column - 1));
        }
        if (front_node->right)
        {
            q.push(make_pair(front_node->right, column + 1));
        }
    }
    for (auto i : nodes)
    {
        cout << i.second.second << " ";
        // i = column number,<check of whether the column has been occupied or not,node value>
    }
    cout << endl;
}
void bottom_view(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    map<int, int> nodes; // The first block stores the column number and the second one contains the node value.
    // Map is sorted according to column number
    queue<pair<Node *, int>> q; // The first block stores the node and the second one stores the column number.
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *front_node = temp.first;
        int column = temp.second;
        nodes[column] = front_node->data; // The node value keeps on getting updated until the bottom of the tree is reached for that column.
        if (front_node->left)
        {
            q.push(make_pair(front_node->left, column - 1));
        }
        if (front_node->right)
        {
            q.push(make_pair(front_node->right, column + 1));
        }
    }
    for (auto i : nodes)
    {
        cout << i.second << " ";
        // i = column number,node value
    }
    cout << endl;
}
void left_view(Node *root, int &index, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == index)
    {
        cout << root->data << " ";
        index++;
    }
    left_view(root->left, index, level + 1);
    left_view(root->right, index, level + 1);
}
int main()
{
    Node *root = build_level_order(root);
    // 1 3 7 4 9 7 -1 -1 -1 -1 -1 -1 -1 -1
    level_order_traversal(root);
    top_view(root);
    bottom_view(root);
    int index = 0;
    left_view(root, index, 0);
}