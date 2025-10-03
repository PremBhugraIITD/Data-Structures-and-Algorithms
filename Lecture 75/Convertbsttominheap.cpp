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
void pre_order_traversal(Node *root, vector<int> in, int &i)
{
    if (root == NULL)
    {
        return;
    }
    root->data = in[i++];
    pre_order_traversal(root->left, in, i);
    pre_order_traversal(root->right, in, i);
}
/*Since, the given BST is already a CBT , so, its structure won't change in the output.*/
Node *convert_to_heap(Node *root)
{
    vector<int> in;
    inorder(root, in);
    int i = 0;
    pre_order_traversal(root, in, i);
    return root;
}
int main()
{
    Node *root = NULL;
    // The given BST is also a complete Binary Tree
    cout << "Enter data to create a BST:" << endl;
    // 4 2 6 1 3 5 7 -1
    takeInput(root);
    cout << "Level order:" << endl;
    level_order_traversal(root);
    root = convert_to_heap(root);
    // All the values on the left heap of every node should be less than those of the right heap
    level_order_traversal(root);
}