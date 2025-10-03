#include <iostream>
#include <list>
#include <limits.h>
#include <unordered_map>
#include <vector>
using namespace std;
vector<pair<pair<int, int>, int>> MST(int n, int m, vector<pair<pair<int, int>, int>> g)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
    vector<int> key(n + 1); // The index represents the node
    vector<int> mst(n + 1);
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    key[1] = 0; // Considering 1 as the source
    parent[1] = -1;
    for (int i = 1; i < n; i++)
    {
        int u;
        int mini = INT_MAX;
        for (int v = 1; v <= n; v++)
        {
            if (!mst[v] && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        mst[u] = true;
        for (auto neighbour : adjList[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if (!mst[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
int main()
{
    vector<pair<pair<int, int>, int>> output1 = MST(5, 14, {{{1, 2}, 2}, {{1, 4}, 6}, {{2, 1}, 2}, {{2, 3}, 3}, {{2, 4}, 8}, {{2, 5}, 5}, {{3, 2}, 3}, {{3, 5}, 7}, {{4, 1}, 6}, {{4, 2}, 8}, {{4, 5}, 9}, {{5, 2}, 5}, {{5, 3}, 7}, {{5, 4}, 9}});
    for (int i = 0; i < output1.size(); i++)
    {
        cout << output1[i].first.first << " " << output1[i].first.second << " " << output1[i].second << endl;
    }
}
// TC = O(n^2)