#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>
using namespace std;
void prepareAdjacencyList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
// TC = O(E), E = Number of edges
void solve(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
// SC = O(E)
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    prepareAdjacencyList(adjList, edges);
    for (int i = 0; i < vertex; i++)
    { // In case there is more than one component in the graph, this loop will be implemented in more than one iterations
        if (!visited[i])
        {
            solve(adjList, visited, ans, i);
        }
    }
    return ans;
}
// TC = O(n + E), n = Number of vertices
// SC = O(n + E)
int main()
{
    vector<pair<int, int>> edges1;
    edges1.push_back(make_pair(0, 1));
    edges1.push_back(make_pair(0, 3));
    edges1.push_back(make_pair(1, 2));
    edges1.push_back(make_pair(2, 3));
    vector<int> output1 = BFS(4, edges1);
    for (auto i : output1)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<pair<int, int>> edges2;
    edges2.push_back(make_pair(0, 1));
    edges2.push_back(make_pair(0, 3));
    edges2.push_back(make_pair(1, 3));
    vector<int> output2 = BFS(4, edges2);
    for (auto i : output2)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<pair<int, int>> edges3;
    edges3.push_back(make_pair(0, 1));
    edges3.push_back(make_pair(0, 2));
    edges3.push_back(make_pair(1, 2));
    edges3.push_back(make_pair(2, 3));
    vector<int> output3 = BFS(4, edges3);
    for (auto i : output3)
    {
        cout << i << " ";
    }
    cout << endl;
}