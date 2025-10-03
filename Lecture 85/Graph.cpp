#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adj;
    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 -> unidrected graph
        // direction = 1 -> directed graph
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u); // If the graph is undirected, the if u is directed to v => v is directed to u
        }
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->  ";
            for (auto j : i.second)
            {
                cout << j << "    ";
            }
            cout << endl;
        }
    }
};
int main()
{
    cout << "Enter the number of nodes:" << endl;
    int n;
    cin >> n;
    cout << "Enter the number of edges:" << endl;
    int m;
    cin >> m;
    Graph<int> g;
    cout << "Describe the edges:" << endl;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.print();
}