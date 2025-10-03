#include <unordered_map>
#include <queue>
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> shortest_path(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = frontNode;
                q.push(i);
            }
        }
    }
    vector<int> ans;
    int curr = t;
    ans.push_back(curr);
    while (curr != s)
    {
        curr = parent[curr];
        ans.push_back(curr);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> output1 = shortest_path({{1, 2}, {2, 3}, {3, 4}, {1, 3}}, 4, 4, 1, 4);
    for (int i = 0; i < output1.size(); i++)
    {
        cout << output1[i] << " ";
    }
    cout << endl;
    vector<int> output2 = shortest_path({{1, 2}, {1, 3}, {1, 4}, {2, 5}, {5, 8}, {3, 8}, {4, 6}, {6, 7}, {7, 8}}, 8, 9, 1, 8);
    for (int i = 0; i < output2.size(); i++)
    {
        cout << output2[i] << " ";
    }
    cout << endl;
}