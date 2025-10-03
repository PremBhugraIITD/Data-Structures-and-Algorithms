#include <iostream>
#include <list>
#include <unordered_map>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    void addEdge(int u, int v, int weight)
    {
        adjList[u].push_back(make_pair(v, weight));
    }
    void print_adjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->  ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << ")   ";
            }
            cout << endl;
        }
    }
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[node] = true;
        for (auto neighbour : adjList[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, visited, st);
            }
        }
        st.push(node);
    }
    void getShortestPath(int src, vector<int> &distance, stack<int> &st)
    {
        distance[src] = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (distance[top] != INT_MAX)
            {
                for (auto i : adjList[top])
                {
                    if (distance[top] + i.second < distance[i.first])
                    {
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.print_adjList();
    // Topological Sort
    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, st);
        }
    }
    int src = 1;
    vector<int> distance(n);
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }
    g.getShortestPath(src, distance, st);
    cout << "The distance array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
}
// TC = O(n+E)
// SC = O(n+E)