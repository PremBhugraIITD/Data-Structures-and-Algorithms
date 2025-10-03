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
void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
Node *Flatten(Node *&root)
{
    if (root == NULL)
    {
        return NULL;
    }
    vector<int> ans;
    inorder(root, ans);
    root = new Node(ans[0]);
    root->left = NULL;
    Node *temp = root;
    int i = 1;
    while (i < ans.size())
    {
        temp->right = new Node(ans[i++]);
        temp->left = NULL;
        temp = temp->right;
    }
    return root;
}
// TC=O(n)
// SC=O(n)
int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST:" << endl;
    // 10 6 12 2 8 11 16 -1
    takeInput(root);
    cout << "Level order:" << endl;
    level_order_traversal(root);
    root = Flatten(root);
    level_order_traversal(root);
}