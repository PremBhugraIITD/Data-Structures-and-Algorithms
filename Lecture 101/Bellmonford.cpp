#include <iostream>
#include <vector>
using namespace std;
vector<int> BellmonFord(int n, int m, int src, vector<vector<int>> edges)
{
    vector<int> distance(n, 1e8);
    distance[src - 1] = 0; // Since, the nodes are 1- indexed
    for (int i = 0; i < n - 1; i++)
    { // Running the formula n-1 times
        for (int j = 0; j < m; j++)
        { // Running the formula for all edges
            int u = edges[j][0] - 1;
            int v = edges[j][1] - 1;
            int w = edges[j][2];
            if (distance[u] != 1e8 && (distance[v] > distance[u] + w))
            {
                distance[v] = distance[u] + w;
            }
        }
    }
    return distance;
    // No need to check for negative cycle in this case
}
// TC = O(n*m)
int main()
{
    vector<int> output = BellmonFord(4, 4, 1, {{1, 2, 4}, {1, 3, 3}, {2, 4, 7}, {3, 4, -2}});
    for (auto i : output)
    {
        cout << i << " ";
    }
    cout << endl;
}