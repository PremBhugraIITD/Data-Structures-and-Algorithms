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
pair<bool, int> sumcheck_and_sum(Node *root)
{ // First block shows whether root is sum tree or not and
    if (root == NULL)
    { // the right part contains the sum
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> left = sumcheck_and_sum(root->left);
    pair<bool, int> right = sumcheck_and_sum(root->right);
    bool condition1 = left.first;
    bool condition2 = right.first;
    bool condition3 = (root->data == left.second + right.second);
    pair<bool, int> ans;
    if (condition1 && condition2 && condition3)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    ans.second = root->data + left.second + right.second;
    return ans;
}
bool isSumTree(Node *root)
{
    return sumcheck_and_sum(root).first;
}
// TC=O(n)
// SC=O(h)
int main()
{
    Node *root = build_level_order(root);
    level_order_traversal(root);
    cout << isSumTree(root) << endl;
}