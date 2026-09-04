#include <unordered_map>
#include <list>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool solveDFS(unordered_map<int, list<int>> &adjList, int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &DFSvisited)
{
    visited[node] = true;
    DFSvisited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            if (solveDFS(adjList, neighbour, visited, DFSvisited))
            {
                return true;
            }
        }
        else if (DFSvisited[neighbour])
        {
            return true;
        }
    }
    DFSvisited[node] = false;
    return false;
}
bool cycleDetection1(int n, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (solveDFS(adjList, i, visited, DFSvisited))
            {
                return true;
            }
        }
    }
    return false;
}
bool cycleDetection2(int n, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1; // Since, nodes are numbered from 1 to n.
        int v = edges[i].second - 1;
        adjList[u].push_back(v);
    }
    vector<int> indegree(n, 0);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int c = 0;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        c++;
        for (auto neighbour : adjList[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return !(c == n);
    // If it is a valid topological sort, i.e., cycle is absent then c==n, otherwise it is an invalid topological sort.
}
// TC = O(n+E)
// SC = O(n+E)
int main()
{
    cout << "Using DFS:" << endl;
    cout << cycleDetection1(5, {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}}) << endl;
    cout << cycleDetection1(5, {{1, 2}, {2, 3}, {3, 4}, {4, 5}}) << endl;
    cout << "Using BFS:" << endl;
    cout << cycleDetection2(5, {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}}) << endl;
    cout << cycleDetection2(5, {{1, 2}, {2, 3}, {3, 4}, {4, 5}}) << endl;
}