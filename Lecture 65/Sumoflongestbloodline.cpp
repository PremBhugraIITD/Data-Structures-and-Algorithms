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
pair<int, int> sum_and_length(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 1);
        return p;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return make_pair(root->data, 1);
    }
    pair<int, int> temp1 = sum_and_length(root->left);
    pair<int, int> temp2 = sum_and_length(root->right);
    int sum_left = temp1.first;
    int sum_right = temp2.first;
    int length_left = temp1.second;
    int length_right = temp2.second;
    pair<int, int> ans;
    ans.second = max(length_left, length_right) + 1;
    if (length_left > length_right)
    {
        ans.first = sum_left + root->data;
    }
    else if (length_left < length_right)
    {
        ans.first = sum_right + root->data;
    }
    else
    {
        ans.first = root->data + max(sum_left, sum_right);
    }
    return ans;
}
int sum_longest_bloodline(Node *root)
{
    return sum_and_length(root).first;
}
// TC=O(n)
// SC=O(h)
int main()
{
    Node *root = build_level_order(root);
    level_order_traversal(root);
    cout << sum_longest_bloodline(root) << endl;
}