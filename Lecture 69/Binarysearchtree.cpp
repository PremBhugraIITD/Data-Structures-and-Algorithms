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
Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
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
int min_value(Node *root)
{
    Node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->data;
}
int max_value(Node *root)
{
    Node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp->data;
}
Node *delete_from_BST(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        // O children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 children
        else
        {
            int mini = min_value(root->right); // We can also choose the max value of root->left
            root->data = mini;
            root->right = delete_from_BST(root->right, mini);
        }
    }
    else if (root->data > val)
    {
        root->left = delete_from_BST(root->left, val);
    }
    else
    {
        root->right = delete_from_BST(root->right, val);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    // 10 7 15 5 9 17 16 19 -1
    cout << "Enter data to create BST:" << endl;
    takeInput(root);
    cout << "Level order:" << endl;
    level_order_traversal(root);
    cout << "Inorder:" << endl;
    in_order_traversal(root);
    cout << endl
         << "Preorder:" << endl;
    pre_order_traversal(root);
    cout << endl
         << "Postorder:" << endl;
    post_order_traversal(root);
    cout << endl
         << max_value(root) << endl;
    cout << min_value(root) << endl;
    root = delete_from_BST(root, 15);
    root = delete_from_BST(root, 10);
    level_order_traversal(root);
}