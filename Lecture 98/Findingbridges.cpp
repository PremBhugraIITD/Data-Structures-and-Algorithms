#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
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
void solve(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, int node)
{
    visited[node] = true;
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            solve(adjList, visited, i);
        }
    }
}
int number_of_components(int v, int e, vector<vector<int>> edges)
{
    int ans = 0;
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    prepareAdjacencyList(adjList, edges);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            solve(adjList, visited, i);
            ans += 1;
        }
    }
    return ans;
}
// TC = O(n+E)
// Returns the number of components in a graph
vector<vector<int>> find_bridges(vector<vector<int>> edges, int v, int e)
{
    int a = number_of_components(v, e, edges); // Total number of components in the original graph
    vector<vector<int>> ans;
    for (int i = 0; i < e; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        auto iterator = edges.begin() + i;
        edges.erase(iterator);                         // TC = O(E)
        int b = number_of_components(v, e - 1, edges); // Total number of components after removing the edge
        if (b > a)
        { // If the number of components increases after removing the edge then the edge was a bridge
            ans.push_back({x, y});
        }
        edges.insert(edges.begin() + i, {x, y}); // TC = O(E)
    }
    return ans;
}
// TC = O(E*(n+E))
int main()
{
    vector<vector<int>> output1 = find_bridges({{1, 2}, {1, 0}, {0, 2}, {0, 4}, {5, 4}, {5, 3}, {3, 4}}, 6, 7);
    cout << output1.size() << endl;
    for (int i = 0; i < output1.size(); i++)
    {
        cout << output1[i][0] << "    " << output1[i][1] << endl;
    }
    vector<vector<int>> output2 = find_bridges({{0, 1}, {3, 1}, {1, 2}, {3, 4}}, 5, 4);
    cout << output2.size() << endl;
    for (int i = 0; i < output2.size(); i++)
    {
        cout << output2[i][0] << "    " << output2[i][1] << endl;
    }
    vector<vector<int>> output3 = find_bridges({{0, 1}, {1, 2}, {2, 0}}, 3, 3);
    cout << output3.size() << endl;
    for (int i = 0; i < output3.size(); i++)
    {
        cout << output3[i][0] << "    " << output3[i][1] << endl;
    }
}