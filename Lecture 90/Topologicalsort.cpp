#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
void solve(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> adjList)
{
    visited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            solve(neighbour, visited, st, adjList);
        }
    }
    st.push(node);
    return;
}
vector<int> topological_sort1(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int p = edges[i][1];
        adjList[u].push_back(p);
    }
    vector<int> ans;
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            solve(i, visited, st, adjList);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
vector<int> topological_sort2(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int p = edges[i][1];
        adjList[u].push_back(p);
    }
    vector<int> indegree(v, 0);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (auto neighbour : adjList[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}
int main()
{
    cout << "Using Stacks:" << endl;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}};
    vector<int> output1 = topological_sort1(edges1, 3, 2);
    for (int i = 0; i < output1.size(); i++)
    {
        cout << output1[i] << " ";
    }
    cout << endl;
    vector<vector<int>> edges2 = {{0, 1}, {0, 3}, {1, 2}, {3, 2}};
    vector<int> output2 = topological_sort1(edges2, 4, 4);
    for (int i = 0; i < output2.size(); i++)
    {
        cout << output2[i] << " ";
    }
    cout << endl;
    cout << "Using Kahn's Algorithm:" << endl;
    vector<vector<int>> edges3 = {{0, 1}, {0, 2}};
    vector<int> output3 = topological_sort2(edges3, 3, 2);
    for (int i = 0; i < output3.size(); i++)
    {
        cout << output3[i] << " ";
    }
    cout << endl;
    vector<vector<int>> edges4 = {{0, 1}, {0, 3}, {1, 2}, {3, 2}};
    vector<int> output4 = topological_sort2(edges4, 4, 4);
    for (int i = 0; i < output4.size(); i++)
    {
        cout << output4[i] << " ";
    }
    cout << endl;
}