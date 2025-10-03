#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
void form_set(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int find_parent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = find_parent(parent[node], parent); // Path compression
}
void union_set(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = find_parent(u, parent);
    v = find_parent(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int weight_of_mst(vector<vector<int>> edges, int n)
{
    sort(edges.begin(), edges.end(), compare); // Your have to define a comparator of yourself because you want to sort the vector of vector according to the third entry in each sub-vector
    vector<int> parent(n);
    vector<int> rank(n);
    form_set(parent, rank, n);
    int total_weight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = find_parent(edges[i][0], parent);
        int v = find_parent(edges[i][1], parent);
        int w = edges[i][2];
        if (u != v)
        { // If the parents of the two nodes connected by the edge are different then the two nodes belong to different components otherwise the same component
            total_weight += w;
            union_set(u, v, parent, rank);
        }
    }
    return total_weight;
}
int main()
{
    cout << weight_of_mst({{0, 1, 3}, {0, 3, 5}, {1, 2, 1}, {2, 3, 8}}, 4) << "      " << weight_of_mst({{1, 2, 6}, {2, 3, 2}, {1, 3, 2}, {1, 0, 2}}, 4) << endl;
}
// Studies show that the functions union_set and find_parent are implemented in almost constant time.
// TC = O(m*log(m)), m = Number of edges