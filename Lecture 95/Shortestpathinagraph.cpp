#include <list>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <limits.h>
#include <iostream>
using namespace std;
vector<int> dijkstra(vector<vector<int>> vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
    vector<int> distance(vertices);
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
    }
    set<pair<int, int>> s; // Set is ordered according to the distance and not the node value, i.e., the first index
    distance[source] = 0;
    s.insert(make_pair(0, source));
    while (!s.empty())
    {
        auto top = *(s.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        s.erase(s.begin());
        for (auto neighbour : adjList[topNode])
        {
            if (distance[neighbour.first] > nodeDistance + neighbour.second)
            {
                auto record = s.find(make_pair(distance[neighbour.first], neighbour.first));
                if (record != s.end())
                { // If record is found in the set
                    s.erase(record);
                }
                distance[neighbour.first] = nodeDistance + neighbour.second;
                s.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }
    return distance;
}
// TC = O(E*log(v))
// SC = O(n+E)
int main()
{
    vector<int> output1 = dijkstra({{0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}}, 9, 14, 0);
    for (int i = 0; i < output1.size(); i++)
    {
        cout << output1[i] << " ";
    }
    cout << endl;
    vector<int> output2 = dijkstra({{2, 1, 3}, {1, 4, 1}, {2, 0, 1}, {1, 0, 7}, {1, 3, 5}, {4, 3, 7}, {0, 3, 2}}, 5, 7, 0);
    for (int i = 0; i < output2.size(); i++)
    {
        cout << output2[i] << " ";
    }
    cout << endl;
}