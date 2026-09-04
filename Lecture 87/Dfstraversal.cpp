#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
void prepareAdjacencyList(unordered_map<int, set<int>> &adjList, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
// TC = O(E), E = Number of edges
void solve(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &component, int node)
{
    component.push_back(node);
    visited[node] = true;
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            solve(adjList, visited, component, i);
        }
    }
}
vector<vector<int>> DFS(int v, int e, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    prepareAdjacencyList(adjList, edges);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            solve(adjList, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}
// TC = O(n + E)
// SC = O(n + E)
int main()
{
    cout << "Case 1:" << endl;
    vector<vector<int>> edges1 = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};
    vector<vector<int>> output1 = DFS(5, 4, edges1);
    for (int i = 0; i < output1.size(); i++)
    {
        for (int j = 0; j < output1[i].size(); j++)
        {
            cout << output1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Case 2:" << endl;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 5}, {3, 6}, {7, 4}, {4, 8}, {7, 8}};
    vector<vector<int>> output2 = DFS(9, 7, edges2);
    for (int i = 0; i < output2.size(); i++)
    {
        for (int j = 0; j < output2[i].size(); j++)
        {
            cout << output2[i][j] << " ";
        }
        cout << endl;
    }
}