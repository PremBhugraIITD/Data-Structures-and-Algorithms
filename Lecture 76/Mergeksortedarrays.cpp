#include <iostream>
#include <queue>
using namespace std;
class info
{
public:
    int data;
    int row, column;
    info(int data, int r, int c)
    {
        this->data = data;
        row = r;
        column = c;
    }
};
// We have to make our custom comparator for info data type
class compare
{
public:
    bool operator()(info a, info b)
    {
        return a.data > b.data;
    }
};
vector<int> mergeSortedArrays(vector<vector<int>> arrays, int k)
{
    priority_queue<info, vector<info>, compare> pq;
    // We will store the first element of every array in the minheap
    for (int i = 0; i < k; i++)
    {
        info temp(arrays[i][0], i, 0);
        pq.push(temp);
    }
    // TC=O(k*log(k))
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().data); // Storing the minimum of the first elements of each array
        int i = pq.top().row;
        int j = pq.top().column;
        pq.pop();
        if (j + 1 < arrays[i].size())
        {
            info next(arrays[i][j + 1], i, j + 1); // Increasing the column number for that array which had the minimum first element
            pq.push(next);
        }
    }
    // TC=O(n*klog(K))
    return ans;
}
// TC=O(n*klog(K))
// SC=O(k)
int main()
{
    vector<vector<int>> arrays;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        arrays.push_back(arr);
    }
    // 4 3 1 5 9 2 45 90 5 2 6 78 100 234 1 0
    for (int i = 0; i < arrays.size(); i++)
    {
        for (int j = 0; j < arrays[i].size(); j++)
        {
            cout << arrays[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> ans = mergeSortedArrays(arrays, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    // Output = 0 1 2 5 6 9 45 78 90 100 234
}