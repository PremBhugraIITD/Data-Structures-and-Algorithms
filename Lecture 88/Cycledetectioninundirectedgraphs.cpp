#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;
bool solveBFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int src)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (auto neighbour : adjList[frontNode])
        {
            if (visited[neighbour] && neighbour != parent[frontNode])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}
bool cycleDetection1(int n, int m, vector<vector<int>> edges)
{
    // Creating Adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (solveBFS(adjList, visited, i))
            {
                return true;
            }
        }
    }
    return false;
}
bool solveDFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node, int parent)
{
    visited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            if (solveDFS(adjList, visited, neighbour, node))
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}
// TC = O(n+E)
bool cycleDetection2(int n, int m, vector<vector<int>> edges)
{
    // Creating Adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (solveDFS(adjList, visited, i, -1))
            {
                return true;
            }
        }
    }
    return false;
}
// TC = O(n+E)
int main()
{
    cout << "Using BFS:" << endl;
    cout << cycleDetection1(3, 2, {{1, 2}, {2, 3}}) << endl;
    cout << cycleDetection1(4, 3, {{1, 4}, {4, 3}, {3, 1}}) << endl;
    cout << "Using DFS:" << endl;
    cout << cycleDetection2(3, 2, {{1, 2}, {2, 3}}) << endl;
    cout << cycleDetection2(4, 3, {{1, 4}, {4, 3}, {3, 1}}) << endl;
}