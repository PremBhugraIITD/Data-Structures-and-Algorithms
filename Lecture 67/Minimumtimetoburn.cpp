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
Node *create_parent_mapping(Node *root, int target, map<Node *, Node *> &node_to_parent)
{ // Creates mapping of node to parent and also finds the target node
    queue<Node *> q;
    q.push(root);
    Node *starting_node = NULL;
    node_to_parent[root] = NULL;
    // Level order traversal of the tree
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->data == target)
        {
            starting_node = temp;
        }
        if (temp->left)
        {
            node_to_parent[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            node_to_parent[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return starting_node;
}
int burn_tree(Node *start, map<Node *, Node *> &node_to_parent)
{
    int time = 0;
    queue<Node *> q;
    map<Node *, bool> burnt;
    q.push(start);
    burnt[start] = true;
    while (!q.empty())
    {
        bool enqued = false;
        int size = q.size();
        for (int i = 0; i < size; i++)
        { // When this for loop ends, neighbours of temp are added to the queue
            Node *temp = q.front();
            q.pop();
            if (temp->left && !burnt[temp->left])
            {
                burnt[temp->left] = true;
                q.push(temp->left);
                enqued = true;
            }
            if (temp->right && !burnt[temp->right])
            {
                burnt[temp->right] = true;
                q.push(temp->right);
                enqued = true;
            }
            if (node_to_parent[temp] && !burnt[node_to_parent[temp]])
            {
                burnt[node_to_parent[temp]] = true;
                q.push(node_to_parent[temp]);
                enqued = true;
            }
        }
        // If any element is pushed into the queue then time gets incremented and the new nodes added to the queue are burnt
        if (enqued == true)
        {
            time++;
        }
    }
    return time;
}
int time_to_burn(Node *root, int target)
{
    map<Node *, Node *> node_to_parent;
    Node *start = create_parent_mapping(root, target, node_to_parent);
    return burn_tree(start, node_to_parent);
}
int main()
{
    Node *root = build_level_order(root);
    // 1 2 3 4 5 -1 7 8 -1 10 -1 -1 -1 -1 -1 -1 -1
    level_order_traversal(root);
    cout << time_to_burn(root, 10) << endl;
}