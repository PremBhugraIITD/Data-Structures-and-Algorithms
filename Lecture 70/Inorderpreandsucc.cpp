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
pair<int, int> inorder_pre_and_succ(Node *root, int key)
{
    Node *temp = root;
    int pre = -1;
    int succ = -1;
    while (temp->data != key)
    {
        if (temp->data < key)
        {
            pre = temp->data;
            temp = temp->right;
        }
        else
        {
            succ = temp->data;
            temp = temp->left;
        }
    }
    // For finding inorder predecessor (maximum element of left subtree)
    Node *left_tree = temp->left;
    while (left_tree)
    {
        pre = left_tree->data;
        left_tree = left_tree->right;
    }
    // For finding inorder successor (minimum element of right subtree)
    Node *right_tree = temp->right;
    while (right_tree)
    {
        succ = right_tree->data;
        right_tree = right_tree->left;
    }
    pair<int, int> ans = make_pair(pre, succ);
    return ans;
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST:" << endl;
    // 15 10 20 8 12 16 25 -1
    takeInput(root);
    cout << "Level order:" << endl;
    level_order_traversal(root);
    cout << inorder_pre_and_succ(root, 10).first << endl;
    cout << inorder_pre_and_succ(root, 10).second << endl;
}