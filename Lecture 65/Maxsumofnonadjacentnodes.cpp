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
pair<int, int> maxsum1_and_maxsum2(Node *root)
{ // The first block stores the maximum sum upto the current level including all the nodes of the current level and the second one contains the maximum sum upto the current level excluding all the nodes of the current level
    if (root == NULL)
    {
        return make_pair(0, 0);
    }
    pair<int, int> left = maxsum1_and_maxsum2(root->left);
    pair<int, int> right = maxsum1_and_maxsum2(root->right);
    pair<int, int> ans;
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first, right.second);
    return ans;
}
int get_max_sum(Node *root)
{
    pair<int, int> ans = maxsum1_and_maxsum2(root);
    return max(ans.first, ans.second);
}
// TC=O(n)
// SC=O(h)
int main()
{
    Node *root = build_level_order(root);
    // 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
    // Output = 16
    level_order_traversal(root);
    cout << get_max_sum(root) << endl;
}