#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
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
vector<int> find_articulation_points(vector<vector<int>> edges, int v, int e){
    vector<int> ans;
    int a = number_of_components(v, e, edges); // Total number of components in the original graph
    for(int i=0;i<v;i++){
        vector<vector<int>> deleted_edges; // Stores the edges connected by the node to be deleted and also the edge's index in the given "edges" vector
        int k = 0;
        for(int j=0;j<edges.size();j++){  
            //This loop deleted all the edges from the "edges" vector which emerge from the node "i"
            if((edges[j][0] == i) || (edges[j][1] == i)){
                deleted_edges.push_back({edges[j][0],edges[j][1],k});
                auto iterator = edges.begin() + j;
                edges.erase(iterator); //TC = O(E)
                j--;  //j should be decremented, since, the size of the "edges" vector has been decremented
            }
            k++; //k iterates over the given "edges" vector
        }
        //TC = O(E^2)
        for(int j = 0;j<edges.size();j++){  //TC = O(E)
            //Since, the "edges" vector has to be passed in its standard form with all the nodes number from 0 to v, we have to decrement the node whose value is greater than the node which was deleted in the modified "edges" vector
            if(edges[j][0]>i){
                edges[j][0]-=1;
            }
            if(edges[j][1]>i){
                edges[j][1]-=1;
            }
        }
        int b = number_of_components(v-1,e-deleted_edges.size(),edges);   //Total number of components present after removing the node
        if(b>a){ // If the number of components increases after removing the node then the node was an articulation point
            ans.push_back(i);
        }
        for(int j = 0;j<edges.size();j++){  //TC = O(E)
            //Since, the value of some nodes was decremented, we have to increment their value again so that the "edges" vector can be reestabilished as original
            if(edges[j][0]>=i){
                edges[j][0]+=1;
            }
            if(edges[j][1]>=i){
                edges[j][1]+=1;
            }   
        }
        for(int j = 0;j<deleted_edges.size();j++){
            edges.insert(edges.begin()+deleted_edges[j][2],{deleted_edges[j][0],deleted_edges[j][1]});
        }
        //TC = O(E^2)
    }
    return ans;
}
//TC = O(n*(n + (E^2)))
int main(){
    vector<int> output1 = find_articulation_points({{1,0},{0,4},{1,4},{2,3},{2,4},{3,4}},5,6);
    cout<<output1.size()<<endl;
    for(int i=0;i<output1.size();i++){
        cout<<output1[i]<<"  ";
    }
    cout<<endl;
    vector<int> output2 = find_articulation_points({{0,1},{1,2},{0,4},{0,3},{3,4}},5,5);
    cout<<output2.size()<<endl;
    for(int i=0;i<output2.size();i++){
        cout<<output2[i]<<"  ";
    }   
    cout<<endl;
}