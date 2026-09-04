#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
using namespace std;
void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, s, adjList);
        }
    }
    s.push(node);
}
void reverse_dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose)
{
    visited[node] = true;
    for (auto neighbour : transpose[node])
    {
        if (!visited[neighbour])
        {
            reverse_dfs(neighbour, visited, transpose);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    // Topological Sort
    stack<int> s;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, s, adjList);
        }
    }
    // Transposing the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
        for (auto neighbour : adjList[i])
        {
            transpose[neighbour].push_back(i);
        }
    }
    // DFS using the topologically ordered stack
    int count = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!visited[top])
        {
            count++;
            reverse_dfs(top, visited, transpose);
        }
    }
    return count;
}
// TC = O(n+E)
int main()
{
    cout << stronglyConnectedComponents(5, {{0, 1}, {1, 2}, {1, 4}, {2, 3}, {3, 2}, {4, 0}}) << endl;
    cout << stronglyConnectedComponents(5, {{0, 2}, {1, 0}, {2, 1}, {2, 3}, {3, 4}}) << endl;
}