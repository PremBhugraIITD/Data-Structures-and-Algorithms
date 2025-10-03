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
// Approach 1
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
Node *make_tree(vector<int> &ans, int l, int u)
{
    if (ans.size() == 0 || l > u)
    {
        return NULL;
    }
    int mid = l + ((u - l) / 2);
    Node *root = new Node(ans[mid]);
    root->left = make_tree(ans, l, mid - 1);
    root->right = make_tree(ans, mid + 1, u);
    return root;
}
Node *Merge1(Node *root1, Node *root2)
{
    vector<int> v1;
    inorder(root1, v1);
    vector<int> v2;
    inorder(root2, v2);
    vector<int> v;
    int i = 0, j = 0;
    // Merging the two sorted arrays
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            v.push_back(v1[i++]);
        }
        else
        {
            v.push_back(v2[j++]);
        }
    }
    while (i < v1.size())
    {
        v.push_back(v1[i++]);
    }
    while (j < v2.size())
    {
        v.push_back(v2[j++]);
    }
    return make_tree(v, 0, v.size() - 1);
}
// TC=O(m+n)
// SC=O(m+n)
// Approach 2
// Converting the BST to sorted doubly linked list
void Flatten(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }
    Flatten(root->right, head);
    root->right = head;
    if (head)
    {
        head->left = root;
    }
    head = root;
    Flatten(root->left, head);
}
// TC=O(n)
// SC=O(h)
// Merging two sorted doubly linked lists
Node *mergeTwoLists(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}
// TC=O(m+n)
// SC=O(1)
// Converting a sorted doubly linked list to BST
int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->right;
        count++;
    }
    return count;
}
Node *make_tree(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }
    Node *left = make_tree(head, n / 2);
    Node *root = head;
    root->left = left;
    head = head->right;
    root->right = make_tree(head, n - (n / 2) - 1);
    return root;
}
Node *Merge2(Node *root1, Node *root2)
{
    // Converting the BST to sorted doubly linked list
    Node *head1 = NULL;
    Node *head2 = NULL;
    Flatten(root1, head1);
    head1->left = NULL;
    Flatten(root2, head2);
    head2->left = NULL;
    // Merging two sorted doubly linked lists
    Node *head = mergeTwoLists(head1, head2);
    // Converting a sorted doubly linked list to BST
    return make_tree(head, countNodes(head));
}
// TC=O(m+n)
// SC=O(h1+h2)
int main()
{
    Node *root1 = NULL;
    takeInput(root1);
    level_order_traversal(root1);
    // 4 2 7 3 -1
    Node *root2 = NULL;
    takeInput(root2);
    level_order_traversal(root2);
    // 5 1 7 -1
    cout << "Approach 1" << endl;
    Node *rootA = Merge1(root1, root2);
    level_order_traversal(rootA);
    cout << "Approach 2" << endl;
    Node *rootB = Merge2(root1, root2);
    level_order_traversal(rootB);
}